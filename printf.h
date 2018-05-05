/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:36:21 by domelche          #+#    #+#             */
/*   Updated: 2018/03/22 16:33:57 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H

# define PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <wchar.h>
# include "libft/libft.h"

/*
**	Bits' positions in mask:
**
**	|#0-+ |
**	|00000|000 00000000
*/

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
	uint16_t		flags;
	int				width;
	int				prec;
	uint8_t			lflags;
	char			conv;
}					t_arg;

t_arg				*ft_argnew();
char				*ft_getarg(t_arg *arg, char *format);
int					ft_isvalid_conv(char c);

char				*ft_putarg(char *format, va_list *ap, int *res);

char				*ft_parse_lflags(char *str, t_arg *arg);

char				*ft_parse_flags(char *str, t_arg *arg);
uint16_t			ft_getmask(char c);

char				*ft_getstr_arg_u(t_arg *arg, va_list *ap);
char				*ft_getstr_arg_i(t_arg *arg, va_list *ap);
char				*ft_getstr_arg_c(t_arg *arg, va_list *ap);
char				*ft_getstr_arg_s(t_arg *arg, va_list *ap);
char				*ft_getstr_arg_p(t_arg *arg, va_list *ap);

char				*ft_handle_width(t_arg *arg, char *str);
char				*ft_handle_prec(t_arg *arg, char *str);
char				*ft_handle_plus(t_arg *arg, char *str);

int					ft_printf(const char *format, ...);

#endif
