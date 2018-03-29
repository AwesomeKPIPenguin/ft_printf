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

static int	ft_iszero(char *str)
{
	while (*str)
	{
		if (*str != ' ' && *str != '0')
			return (0);
		++str;
	}
	return (1);
}

char		*ft_handle_sharp(t_arg *arg, char *str)
{
	char	*res;

	if ((arg->flags & F_SHARP) && !ft_iszero(str))
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

static void ft_strjoin_3(char *dst, char *str_0, char *str_1, char *str_2)
{
	int 	i;

	i = 0;
	if (str_0)
	{
		while (*str_0)
			dst[i++] = *(str_0++);
		free(str_0);
	}
	if (str_1)
	{
		while (*str_1)
			dst[i++] = *(str_1++);
		free(str_1);
	}
	if (str_2)
	{
		while (*str_2)
			dst[i++] = *(str_2++);
		free(str_2);
	}
}

char		*ft_handle_width(t_arg *arg, char *str)
{
	char	*res;
	char	*sharp_str;
	char 	*pad_str;
	char	fill_char;
	int		pad_len;
	int		len;
	int		sharp_len;

	len = ft_strlen(str);
	sharp_str = NULL;
	sharp_len = 0;
	pad_str = NULL;
	if (arg->flags & F_SHARP)
	{
		sharp_str = (arg->conv == 'o') ? ft_strdup("0") : ft_strdup("0X");
		sharp_len = ft_strlen(sharp_str);
	}
	pad_len = arg->width - len - sharp_len;
	if (pad_len > 0)
	{
		fill_char = (arg->flags & F_ZERO) ? '0' : ' ';
		if (!(res = ft_memalloc((arg->width + 1) * sizeof(char))))
			return (NULL);
		if (!(pad_str = malloc((pad_len + 1) * sizeof(char))))
			return (NULL);
		pad_str = ft_memset(pad_str, fill_char, pad_len);
		pad_str[pad_len] = 0;
		if (*pad_str == '0')
			ft_strjoin_3(res, sharp_str, pad_str, str);
		else if (arg->flags & F_MINUS)
			ft_strjoin_3(res, sharp_str, str, pad_str);
		else
			ft_strjoin_3(res, pad_str, sharp_str, str);
	}
	else if (sharp_str)
	{
		res = ft_strjoin(sharp_str, str);
		free(sharp_str);
		free(str);
	}
	return (res);
}

char		*ft_handle_prec(t_arg *arg, char *str)
{
	char	*res;
	int		len;
	int		sign;

	len = ft_strlen(str);
	sign = (*str == '-') ? 1 : 0;
	if (!(F_ZERO & ft_getmask(arg->conv)) && arg->prec > len - sign)
		return (str);
	if (!(res = malloc(arg->prec * sizeof(char))))
		return (NULL);
	res = ft_memset(&(res[sign]), '0', arg->prec - len);
	res = ft_strcpy(&(res[sign + arg->prec - len]), &(str[sign]));
	if (sign)
		res[0] = '-';
	free(str);
	return (res);
}

char		*ft_handle_plus(t_arg *arg, char *str)
{
	char	*res;

	if ((arg->flags & F_PLUS) && *str != '-')
	{
		res = ft_strjoin("+", str);
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

static void ft_print_arg_u(t_arg *arg, va_list *ap)
{
	unsigned long long	data;
	int					base;
	char				*str;
	char				*to_free;

	data = va_arg(*ap, unsigned long long);
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

static void ft_print_arg_i(t_arg *arg, va_list *ap)
{
	long long	data;
	char		*str;

	data = va_arg(*ap, long long);
	if (arg->lflags & LF_LL)
		str = ft_itoa(data);
	else if (arg->lflags & LF_L)
		str = ft_itoa((long)data);
	else if (arg->lflags & LF_H)
		str = ft_itoa((short)data);
	else if (arg->lflags & LF_HH)
		str = ft_itoa((char)data);
	else if (arg->lflags & LF_J)
		str = ft_itoa((intmax_t)data);
	else if (arg->lflags & LF_Z)
		str = ft_itoa((size_t)data); // <----------------------------------z
	else
		str = ft_itoa((int)data);
	ft_putstr(str);
	free(str);
}

static void	ft_print_arg_c(t_arg *arg, va_list *ap)
{
	wint_t	data;

	data = va_arg(*ap, wint_t);
	if ((arg->lflags & LF_L) | (arg->lflags & LF_LL))
		ft_putwchar(data);
	else
		ft_putchar((unsigned char)data);
}

static void	ft_print_arg_s(t_arg *arg, va_list *ap)
{
	wchar_t	*data;

	data = va_arg(*ap, wchar_t *);
	if (!data)
		return (ft_putstr("(null)"));
	if ((arg->lflags & LF_L) | (arg->lflags & LF_LL))
		ft_putwstr(data);
	else
		ft_putstr((char *)data);
}

static void	ft_print_arg_p(t_arg *arg, va_list *ap)
{
	void	*data;
	char	*str;
	char	*to_free;

	(void)arg;
	data = va_arg(*ap, void *);
	str = ft_uitoa_base((unsigned long long)data, 16);
	to_free = str;
	str = ft_strjoin("0x", str);
	free(to_free);
	ft_putstr(str);
	free(str);
}

static void	ft_print_arg(t_arg *arg, va_list *ap)
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

void		ft_print(va_list *ap, char *format, t_list *args)
{
	int 	i;

	i = -1;
	while (format[++i])
	{
		if (format[i] != '%')
			ft_putchar(format[i]);
		else
		{
			ft_print_arg((t_arg *)args->content, ap);
			args = args->next;
		}
	}
}
