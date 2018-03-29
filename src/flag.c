/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:34:50 by domelche          #+#    #+#             */
/*   Updated: 2018/03/22 14:37:53 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int			ft_parse_flags(char *str, t_arg *arg)
{
	int		i;

	i = 0;
	while (1)
	{
		if (str[i] == '#')
			arg->flags |= F_SHARP;
		else if (str[i] == '0')
			arg->flags |= F_ZERO;
		else if (str[i] == '-')
			arg->flags |= F_MINUS;
		else if (str[i] == '+')
			arg->flags |= F_PLUS;
		else if (str[i] == ' ')
			arg->flags |= F_SPACE;
		else
		{
			if (arg->flags & F_MINUS)
				arg->flags &= ~F_ZERO;
			if (arg->flags & F_PLUS)
				arg->flags &= ~F_SPACE;
			return (i);
		}
		i++;
	}
}

uint16_t	ft_getmask(char c)
{
	if (c == 'd' || c == 'i')
		return (0x7800);
	else if (c == 'o' || c == 'x' || c == 'X')
		return (0xE000);
	else if (c == 'u')
		return (0x6000);
	else
		return (0x2000);
}
