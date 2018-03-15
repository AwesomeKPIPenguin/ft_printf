/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:36:21 by domelche          #+#    #+#             */
/*   Updated: 2018/03/09 18:04:20 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H

# define PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct	s_flag
{
	int			sharp;
	int			zero;
	int			minus;
	int			plus;
	int			space;
}				t_flag;

typedef struct	s_lflag
{
	int			l;
	int			ll;
	int			h;
	int			hh;
	int			j;
	int			z;
}				t_lflag;

typedef struct	s_arg
{
	t_flag		*flags;
	int			width;
	int			prec;
	t_lflag		*lflags;
	char		conv;
}				t_arg;

t_flag			*ft_flagnew();
int				ft_parse_lflags(char *str, t_arg *arg);

t_lflag			*ft_lflagnew();
int				ft_parse_flags(char *str, t_arg *arg);

char			*ft_create_args_list(t_list **list, char *format);

int				ft_printf(const char *format, ...);

#endif
