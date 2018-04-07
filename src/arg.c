/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:34:31 by domelche          #+#    #+#             */
/*   Updated: 2018/03/31 17:13:34 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

// debug **********************************************************************

void	ft_print_arg(t_arg *arg)
{
	if (!arg)
	{
		printf("\n(null)\n\n");
		return ;
	}
	printf("\n{\n\tflags:\n\t{\n\t\t'#0-+ '\n\t\t %d%d%d%d%d\n\t}\n\t\
width: %d\n\tprecision: %d\n\t\
length flags:\n\t{\n\t\tl  ll h  hh j  z\n\t\t%d  %d  %d  %d  %d  %d\n\t}\n\t\
conversion: %c\n}\n\n",
			(arg->flags & F_SHARP) ? 1 : 0, (arg->flags & F_ZERO) ? 1 : 0,
			(arg->flags & F_MINUS) ? 1 : 0, (arg->flags & F_PLUS) ? 1 : 0, 
			(arg->flags & F_SPACE) ? 1 : 0,
			arg->width, arg->prec,
			(arg->lflags & LF_L) ? 1 : 0, (arg->lflags & LF_LL) ? 1 : 0,
			(arg->lflags & LF_H) ? 1 : 0, (arg->lflags & LF_HH) ? 1 : 0,
			(arg->lflags & LF_J) ? 1 : 0, (arg->lflags & LF_Z) ? 1 : 0,
			arg->conv);
}

void	ft_print_args(t_list *args)
{
	t_list	*node;

	node = args;
	while (node)
	{
		ft_print_arg((t_arg *)node->content);
		node = node->next;
	}
}

// ****************************************************************************



t_arg	*ft_argnew()
{
	t_arg	*arg;

	arg = (t_arg *)ft_memalloc(sizeof(t_arg));
	return (arg);
}

int		ft_get_conv(t_arg *arg, char conv)
{
	char	res;

	res = 0;
	if (conv == 's' || conv == 'd' || conv == 'i' || conv == 'o' ||
		conv == 'u' || conv == 'x' || conv == 'X' || conv == 'c' ||
		conv == 'p')
		res = conv;
	else if (conv == 'D' || conv == 'C' || conv == 'S' || conv == 'O' ||
			conv == 'U')
	{
		arg->lflags |= LF_L;
		res = ft_tolower(conv);
	}
	if (res == 'x' || res == 'X' || res == 'u' || res == 'o')
	{
		if (res == 'u')
			arg->flags &= ~F_SHARP;
		arg->flags &= ~(F_PLUS | F_SPACE);
	}
	else
		arg->flags &= ~F_SHARP;
	arg->flags &= ft_getmask(res);
	return (res);
}

char	*ft_getarg(t_arg *arg, char *format)
{
	format = ft_parse_flags(format, arg);
	arg->width = ft_atoi(format);
	while (ft_isdigit(*format))
		++format;
	if (*format == '.')
	{
		arg->prec = ft_atoi(++format);
		arg->flags &= ~F_ZERO;
	}
	while (ft_isdigit(*format))
		++format;
	format = ft_parse_lflags(format, arg);
	arg->conv = ft_get_conv(arg, *format);
	if (!arg->conv)
	{
		free(arg);
		return (NULL);
	}
	return (++format);
}
