/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 15:54:11 by domelche          #+#    #+#             */
/*   Updated: 2018/04/13 16:05:53 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static char	*ft_handle_flags(t_arg *arg, char *str)
{
	char	*res;

	res = ft_strdup(str);
	res = ft_handle_prec(arg, res);
	res = ft_handle_plus(arg, res);
	res = ft_handle_width(arg, res);
	return (res);
}

static char *ft_argtoa(t_arg *arg, va_list *ap)
{
	if (arg->conv == '%')
		return (ft_strdup("%"));
	else if (arg->conv == 'd' || arg->conv == 'i')
		return (ft_getstr_arg_i(arg, ap));
	else if (arg->conv == 'u' || arg->conv == 'o' ||
			 arg->conv == 'x' || arg->conv == 'X')
		return (ft_getstr_arg_u(arg, ap));
	else if (arg->conv == 'c')
		return (ft_getstr_arg_c(arg, ap));
	else if (arg->conv == 's')
		return (ft_getstr_arg_s(arg, ap));
	else
		return (ft_getstr_arg_p(arg, ap));
}

char	*ft_putarg(char *format, va_list *ap, int *res)
{
	t_arg	*arg;
	char	*str;

	arg = ft_argnew();
	if (!(format = ft_getarg(arg, format)))
		return (NULL);
	str = ft_argtoa(arg, ap);
	str = ft_handle_flags(arg, str);
	*res += ft_strlen(str);
	ft_putstr(str);
	return (format);
}
