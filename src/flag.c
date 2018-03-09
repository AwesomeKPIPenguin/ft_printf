/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:34:50 by domelche          #+#    #+#             */
/*   Updated: 2018/03/09 18:04:19 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

t_flag	*ft_flagnew()
{
	t_flag	*flags;

	flags = ft_smemalloc(sizeof(t_flag), "ft_flagnew");
	flags->sharp = 0;
	flags->zero = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->space = 0;
	return (flags);
}

int		ft_parse_flags(char *str, t_arg *arg)
{
	int		i;

	i = 0;
	while (1)
	{
		if (str[i] == '#')
			arg->flags->sharp = 1;
		else if (str[i] == '0')
			arg->flags->zero = 1;
		else if (str[i] == '-')
			arg->flags->minus = 1;
		else if (str[i] == '+')
			arg->flags->plus = 1;
		else if (str[i] == ' ')
			arg->flags->space = 1;
		else
		{
			if (arg->flags->minus)
				arg->flags->zero = 0;
			if (arg->flags->plus)
				arg->flags->space = 0;
			return (i);
		}
		i++;
	}
}
