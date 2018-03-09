/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lflag.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:35:39 by domelche          #+#    #+#             */
/*   Updated: 2018/03/09 17:26:31 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

t_lflag	*ft_lflagnew()
{
	t_lflag	*lflags;

	lflags = ft_smemalloc(sizeof(t_lflag), "ft_lflagnew");
	lflags->l = 0;
	lflags->ll = 0;
	lflags->h = 0;
	lflags->hh = 0;
	lflags->j = 0;
	lflags->z = 0;
	return (lflags);
}

int		ft_parse_lflags(char *str, t_arg *arg)
{
	int		i;

	i = -1;
	while (++i > -1)
	{
		if (str[i] == 'l')
		{
			if (str[i + 1] == 'l')
			{
				arg->lflags->ll = 1;
				++i;
			}
			else
				arg->lflags->l = 1;
		}
		else if (str[i] == 'h')
		{
			if (str[i + 1] == 'h')
			{
				arg->lflags->hh = 1;
				++i;
			}
			else
				arg->lflags->h = 1;
		}
		else if (str[i] == 'j')
			arg->lflags->j = 1;
		else if (str[i] == 'z')
			arg->lflags->z = 1;
		else
			return (i);
	}
	return (0);
}
