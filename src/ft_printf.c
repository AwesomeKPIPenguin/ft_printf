/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:35:29 by domelche          #+#    #+#             */
/*   Updated: 2018/05/05 14:54:28 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static void	ft_print_format(va_list *ap, int *res, char *f, t_arg *arg)
{
	char	*tmp;

	tmp = f;
	while (f && *f)
	{
		if (*f != '%')
		{
			++f;
			++(*res);
		}
		else
		{
			write(1, tmp, f - tmp);
			f = ft_putarg(++f, ap, res, arg);
			tmp = f;
		}
	}
	write(1, tmp, f - tmp);
}

int			ft_printf(const char *format, ...)
{
	va_list ap;
	char	*f;
	char	*to_free;
	int		res;
	t_arg	*arg;

	if (!ft_strchr(format, '%'))
	{
		ft_putstr(format);
		return ((int)ft_strlen(format));
	}
	va_start(ap, format);
	f = ft_strdup(format);
	to_free = f;
	res = 0;
	arg = ft_argnew();
	ft_print_format(&ap, &res, f, arg);
	va_end(ap);
	free(to_free);
	free(arg);
	return (res);
}
