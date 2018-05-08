/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 15:54:11 by domelche          #+#    #+#             */
/*   Updated: 2018/05/05 14:59:15 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static void	ft_fix_sign(t_arg *arg, char *str)
{
	int		i;

	i = 0;
	if ((arg->conv == 'd' || arg->conv == 'i') && *str == '0')
	{
		while (str[i] == '0')
			++i;
		if (str[i] == '-' || str[i] == '+' ||
			(arg->flags & F_SPACE && str[i] == ' '))
		{
			str[0] = str[i];
			str[i] = '0';
		}
	}
}

static char	*ft_handle_flags(t_arg *arg, char *str)
{
	char	*res;

	res = str;
	res = ft_handle_prec(arg, res);
	res = ft_handle_plus(arg, res);
	res = ft_handle_width(arg, res);
	return (res);
}

static void	ft_handle_nullchar(t_arg *arg, char *str, int *res)
{
	int		len;

	str[0] = -1;
	str = ft_handle_flags(arg, str);
	len = ft_strlen(str);
	*res += len;
	ft_strrplc(str, -1, 0);
	write(1, str, len);
}

static char	*ft_argtoa(t_arg *arg, va_list *ap)
{
	char	*str;

	if (!ft_isvalid_conv(arg->conv))
	{
		if (!(str = (char *)ft_memalloc(2 * sizeof(char))))
			return (NULL);
		str[0] = arg->conv;
		arg->conv = 'c';
	}
	else
	{
		if (arg->conv == '%')
			str = ft_strdup("%");
		else if (arg->conv == 'd' || arg->conv == 'i')
			str = ft_getstr_arg_i(arg, ap);
		else if (arg->conv == 'p')
			str = ft_getstr_arg_p(arg, ap);
		else if (arg->conv == 'c')
			str = ft_getstr_arg_c(arg, ap);
		else if (arg->conv == 's')
			str = ft_getstr_arg_s(arg, ap);
		else
			str = ft_getstr_arg_u(arg, ap);
	}
	return (str);
}

char		*ft_putarg(char *format, va_list *ap, int *res, t_arg *arg)
{
	char	*str;

	ft_clrarg(arg);
	format = ft_getarg(arg, format);
	if (!arg->conv)
		return (format);
	str = ft_argtoa(arg, ap);
	if (arg->conv == 'c' && !*str)
		ft_handle_nullchar(arg, str, res);
	else
	{
		str = ft_handle_flags(arg, str);
		ft_fix_sign(arg, str);
		*res += ft_strlen(str);
		//ft_putstr(str);
		free(str);
	}
	return (format);
}
