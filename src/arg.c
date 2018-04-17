/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:34:31 by domelche          #+#    #+#             */
/*   Updated: 2018/04/13 16:03:36 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

t_arg	*ft_argnew()
{
	t_arg	*arg;

	arg = (t_arg *)ft_memalloc(sizeof(t_arg));
	arg->prec = -1;
	return (arg);
}

int		ft_get_conv(t_arg *arg, char conv)
{
	char	res;

	res = 0;
	if (conv == 's' || conv == 'd' || conv == 'i' || conv == 'o' ||
		conv == 'u' || conv == 'x' || conv == 'X' || conv == 'c' ||
		conv == 'p' || conv == '%')
		res = conv;
	else if (conv == 'D' || conv == 'C' || conv == 'S' || conv == 'O' ||
			conv == 'U')
	{
		arg->lflags |= LF_L;
		res = ft_tolower(conv);
	}
	if (res == 'x' || res == 'X' || res == 'u' || res == 'o')
	{
		if (res == 'u')
			arg->flags &= ~F_SHARP;
		arg->flags &= ~(F_PLUS | F_SPACE);
	}
	else
		arg->flags &= ~F_SHARP;
	arg->flags &= ft_getmask(res);
	return (res);
}

char	*ft_getarg(t_arg *arg, char *format)
{
	format = ft_parse_flags(format, arg);
	arg->width = ft_atoi(format);
	while (ft_isdigit(*format))
		++format;
	if (*format == '.')
	{
		arg->prec = ft_atoi(++format);
		arg->flags &= ~F_ZERO;
	}
	while (ft_isdigit(*format))
		++format;
	format = ft_parse_lflags(format, arg);
	arg->conv = ft_get_conv(arg, *format);
	if (!arg->conv)
	{
		arg->width = -1;
		return (format);
	}
	return (++format);
}
