/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:36:21 by domelche          #+#    #+#             */
/*   Updated: 2018/03/22 15:47:11 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H

# define PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include "libft/libft.h"
# include <stdio.h>

# define F_SHARP	0x8000
# define F_ZERO		0x4000
# define F_MINUS	0x2000
# define F_PLUS		0x1000
# define F_SPACE	0x800

# define LF_L		0x80
# define LF_LL		0x40
# define LF_H		0x20
# define LF_HH		0x10
# define LF_J		0x8
# define LF_Z		0x4

typedef struct		s_arg
{
	short			flags;
	int				width;
	int				prec;
	unsigned char	lflags;
	char			conv;
}					t_arg;

int					ft_parse_lflags(char *str, t_arg *arg);

int					ft_parse_flags(char *str, t_arg *arg);

char				*ft_create_args_list(t_list **list, char *format);

void				ft_print(va_list *ap, char *format, t_list *args);

int					ft_printf(const char *format, ...);

#endif
