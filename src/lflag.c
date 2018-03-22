/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lflag.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:35:39 by domelche          #+#    #+#             */
/*   Updated: 2018/03/22 13:11:34 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static int	ft_parse_lflags_l(char *str, t_arg *arg, int *i)
{
	if (str[*i] == 'l')
	{
		if (str[*i + 1] == 'l')
		{
			arg->lflags |= LF_LL;
			++(*i);
		}
		else
			arg->lflags |= LF_L;
		return (1);
	}
	else
		return (0);
}

static int	ft_parse_lflags_h(char *str, t_arg *arg, int *i)
{
	if (str[*i] == 'h')
	{
		if (str[*i + 1] == 'h')
		{
			arg->lflags |= LF_HH;
			++(*i);
		}
		else
			arg->lflags |= LF_H;
		return (1);
	}
	else
		return (0);
}

int			ft_parse_lflags(char *str, t_arg *arg)
{
	int		i;

	i = -1;
	while (++i > -1)
	{
		if (ft_parse_lflags_l(str, arg, &i))
			;
		else if (ft_parse_lflags_h(str, arg, &i))
			;
		else if (str[i] == 'j')
			arg->lflags |= LF_J;
		else if (str[i] == 'z')
			arg->lflags |= LF_Z;
		else
			return (i);
	}
	return (0);
}
