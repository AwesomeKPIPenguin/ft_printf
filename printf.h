
#ifndef PRINTF_H

# define PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h>

typedef enum	e_type
{
				INT,
				U_INT,
				DOUBLE,
				CHAR_PTR,
				WCHAR_PTR,
				VOID_PTR,
				INT_PTR
}				t_type;

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

t_flag	*ft_flagnew();
t_lflag	*ft_lflagnew();

int		ft_printf(const char *format, ...);

#endif
