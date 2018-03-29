/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 17:09:42 by domelche          #+#    #+#             */
/*   Updated: 2018/03/22 16:32:44 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

char		*ft_handle_sharp(t_arg *arg, char *str)
{
	char	*res;

	if ((arg->flags & F_SHARP & ft_getmask(arg->conv)) && *str != '0')
	{
		if (arg->conv == 'x')
			res = ft_strjoin("0x", str);
		else if (arg->conv == 'X')
			res = ft_strjoin("0X", str);
		else
			res = ft_strjoin("0", str);
		free(str);
		str = res;
	}
	return (str);
}

char		*ft_handle_prec(t_arg *arg, char *str)
{
	char	*res;
	int		len;
	int		sign;

	if (!(F_ZERO & ft_getmask(arg->conv)))
		return (str);
	len = ft_strlen(str);
	sign = (*str == '-') ? 1 : 0;
	if (arg->prec > len)
	{
		if (!(res = malloc(arg->prec * sizeof(char))))
			return (NULL);
		res = ft_memset(&(res[sign]), '0', arg->prec - len);
		res = ft_strcpy(&(res[arg->prec - len - 1]), &(str[sign]));
		if (sign)
			res[0] = '-';
	}
	free(str);
	return (res);
}

char		*ft_handle_plus(t_arg *arg, char *str)
{
	char	*res;

	if ((arg->flags & F_PLUS & ft_getmask(arg->conv)) && *str != '-')
	{
		res = ft_strjoin("+", str);
		free(str);
		str = res;
	}
	return (str);
}


char		*ft_handle_width(t_arg *arg, char *str)
{
	char	*res;
	char	filler;
	int		pad;
	char	*pad_str;
	int		len;

	len = ft_strlen(str);
	pad = arg->width - len;
	if (pad > 0)	
	{
		filler = (arg->flags & F_ZERO & ft_getmask(arg->conv)) ? '0' : ' ';
		if (!(res = malloc(arg->width * sizeof(char))))
			return (NULL);
		res = ft_memset(res, filler, arg->width);
		if (arg->flags & F_MINUS)
			res = ft_strcpy(res, str);
		else
			res = ft_strcpy(&(res[arg->width - len]), str);
		free(str);
		str = res;
	}
	return (str);
}

char		*ft_handle_flags(t_arg *arg, char *str)
{
	char	*res;

	res = ft_strdup(str);
	res = ft_handle_prec(arg, res);
	res = ft_handle_plus(arg, res);
	res = ft_handle_sharp(arg, res);
	res = ft_handle_width(arg, res);
}

static char	*ft_getstr_arg_u(t_arg *arg, unsigned long long data, int base)
{
	if (arg->lflags & LF_LL)
		return (ft_uitoa_base(data, base));
	else if (arg->lflags & LF_L)
		return (ft_uitoa_base((unsigned long)data, base));
	else if (arg->lflags & LF_H)
		return (ft_uitoa_base((unsigned short)data, base));
	else if (arg->lflags & LF_HH)
		return (ft_uitoa_base((char)data, base));
	else if (arg->lflags & LF_J)
		return (ft_uitoa_base((uintmax_t)data, base));
	else if (arg->lflags & LF_Z)
		return (ft_uitoa_base((size_t)data, base));
	else
		return (ft_uitoa_base((unsigned int)data, base));
}

static void ft_print_arg_u(t_arg *arg, va_list ap)
{
	unsigned long long	data;
	int					base;
	char				*str;
	char				*to_free;

	data = va_arg(ap, unsigned long long);
	base = 10;
	if (arg->conv == 'x' || arg->conv == 'X')
		base = 16;
	else if (arg->conv == 'o')
		base = 8;
	str = ft_getstr_arg_u(arg, data, base);
	if (arg->conv == 'x')
	{
		to_free = str;
		str = ft_strmap(str, (char (*)(char))ft_tolower);
		free(to_free);
	}
	ft_putstr(str);
	free(str);
}

static void ft_print_arg_i(t_arg *arg, va_list ap)
{
	long long	data;
	char		*str;

	data = va_arg(ap, long long);
	if (arg->lflags & LF_LL)
		str = ft_uitoa(data);
	else if (arg->lflags & LF_L)
		str = ft_uitoa((long)data);
	else if (arg->lflags & LF_H)
		str = ft_uitoa((short)data);
	else if (arg->lflags & LF_HH)
		str = ft_uitoa((char)data);
	else if (arg->lflags & LF_J)
		str = ft_uitoa((intmax_t)data);
	else if (arg->lflags & LF_Z)
		str = ft_uitoa((size_t)data); // <----------------------------------z
	else
		str = ft_uitoa((int)data);
	ft_putstr(str);
	free(str);
}

static void	ft_print_arg_c(t_arg *arg, va_list ap)
{
	wint_t	data;

	data = va_arg(ap, wint_t);
	if ((arg->lflags & LF_L) | (arg->lflags & LF_LL))
		ft_putwchar(data);
	else
		ft_putchar((unsigned char)data);
}

static void	ft_print_arg_s(t_arg *arg, va_list ap)
{
	wchar_t	*data;

	data = va_arg(ap, wchar_t i*);
	if (!data)
		return (ft_putstr("(null)"));
	if ((arg->lflags & LF_L) | (arg->lflags & LF_LL))
		ft_putwstr(data);
	else
		ft_putstr((char *)data);
}

static void	ft_print_arg_p(t_arg *arg, va_list ap)
{
	void	*data;
	char	*str;
	char	*to_free;

	(void)arg;
	data = va_arg(ap, void *);
	str = ft_uitoa_base((unsigned long long)data, 16);
	to_free = str;
	str = ft_strjoin("0x", str);
	free(to_free);
	ft_putstr(str);
}

static void	ft_print_arg(t_arg *arg, va_list ap)
{
	if (arg->conv == 'd' || arg->conv == 'i')
		ft_print_arg_i(arg, ap);
	else if (arg->conv == 'u' || arg->conv == 'o' ||
			arg->conv == 'x' || arg->conv == 'X')
		ft_print_arg_u(arg, ap);
	else if (arg->conv == 'c')
		ft_print_arg_c(arg, ap);
	else if (arg->conv == 's')
		ft_print_arg_s(arg, ap);
	else if (arg->conv == 'p')
		ft_print_arg_p(arg, ap);
}

void		ft_print(va_list ap, char *format, t_list *args)
{
	int 	i;

	i = -1;
	while (format[++i])
	{
		if (format[i] != '%')
			ft_putchar(format[i]);
		else
		{
			ft_print_arg((t_arg *)args->content, *ap);
			args = args->next;
		}
	}
}
