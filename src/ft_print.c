/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 17:09:42 by domelche          #+#    #+#             */
/*   Updated: 2018/03/22 16:20:17 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

char		*ft_handle_flags(t_arg *arg, char *str)
{
	char	*res;
	int		pad;
	
	pad = arg->width - ft_strlen(str);
	pad = (pad < 0) ? 0 : pad;

}

static char	*ft_getstr_arg_i(t_arg *arg, long long data, int base)
{
	if (arg->lflags & LF_LL)
		return (ft_itoa_base(data, base));
	else if (arg->lflags & LF_L)
		return (ft_itoa_base((long)data, base));
	else if (arg->lflags & LF_H)
		return (ft_itoa_base((short)data, base));
	else if (arg->lflags & LF_HH)
		return (ft_itoa_base((signed char)data, base));
	else if (arg->lflags & LF_J)
		return (ft_itoa_base((intmax_t)data, base));
	else if (arg->lflags & LF_Z)
		return (ft_itoa_base((size_t)data, base)); // <---------- z flag ----
	else
		return (ft_itoa_base((int)data, base));
}

static void ft_print_arg_i(t_arg *arg, va_list ap)
{
	long long	data;
	int			base;
	char		*str;
	char		*to_free;

	data = va_arg(ap, long long);
	base = 10;
	if (arg->conv == 'x' || arg->conv == 'X')
		base = 16;
	else if (arg->conv == 'o' || arg->conv == 'O')
		base = 8;
	str = ft_getstr_arg_i(arg, data, base);
	if (arg->conv == 'x')
	{
		to_free = str;
		str = ft_strmap(str, (char (*)(char))ft_tolower);
		free(to_free);
	}
	ft_putstr(str);
	free(str);
}

static void ft_print_arg_u(t_arg *arg, va_list ap)
{
	unsigned long long	data;
	char				*str;

	data = va_arg(ap, unsigned long long);
	if (arg->lflags & LF_LL)
		str = ft_uitoa(data);
	else if (arg->lflags & LF_L)
		str = ft_uitoa((unsigned long)data);
	else if (arg->lflags & LF_H)
		str = ft_uitoa((unsigned short)data);
	else if (arg->lflags & LF_HH)
		str = ft_uitoa((unsigned char)data);
	else if (arg->lflags & LF_J)
		str = ft_uitoa((uintmax_t)data);
	else if (arg->lflags & LF_Z)
		str = ft_uitoa((size_t)data);
	else
		str = ft_uitoa((unsigned int)data);
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

	data = va_arg(ap, wchar_t *);
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
	if (arg->conv == 'd' || arg->conv == 'i' || arg->conv == 'o' ||
		arg->conv == 'x' || arg->conv == 'X')
		ft_print_arg_i(arg, ap);
	else if (arg->conv == 'u')
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
			ft_print_arg((t_arg *)args->content, *ap);
			args = args->next;
		}
	}
}
