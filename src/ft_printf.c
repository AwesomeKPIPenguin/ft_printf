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

int		ft_printf(const char *format, ...)
{
	va_list ap;
	char	*f;
	char	*to_free;
	int		res;
	char	*str;

	if (!ft_strchr(format, '%'))
	{
		ft_putstr(format);
		return ((int)ft_strlen(format));
	}
	va_start(ap, format);
	f = ft_strdup(format);
	to_free = f;
	res = 0;
	while (f && *f)
		if (*f != '%')
		{
			ft_putchar(*(f++));
			++res;
		}
		else
			f = ft_putarg(++f, &ap, &res);
	va_end(ap);
	free(to_free);
	return (res);
}
