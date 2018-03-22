/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:35:29 by domelche          #+#    #+#             */
/*   Updated: 2018/03/22 15:45:08 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int		ft_printf(const char *format, ...)
{
	va_list ap;
	t_list	*args;
	char 	*str;

	if (!ft_strchr(format, '%'))
	{
		ft_putstr(format);
		return ((int)ft_strlen(format));
	}
	va_start(ap, format);
	str = ft_strdup(format);
	if (!(str = ft_create_args_list(&args, str)))
		return (0);
	ft_print(&ap, str, args);
	va_end(ap);
	return (1);
}
