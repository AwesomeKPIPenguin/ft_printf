/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 17:09:42 by domelche          #+#    #+#             */
/*   Updated: 2018/03/15 17:09:44 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static void ft_print_arg_i(t_arg *arg, va_list ap)
{
	long long	data;

	data = va_arg(ap, long long);
	if (arg->lflags->ll)
		ft_putstr(ft_itoa(data));
	else if (arg->lflags->l)
		ft_putstr(ft_itoa((long)data));
	else if (arg->lflags->h)
		ft_putstr(ft_itoa((short)data));
	else if (arg->lflags->hh)
		ft_putstr(ft_itoa((signed char)data));
	else if (arg->lflags->j)
		ft_putstr(ft_itoa((intmax_t)data));
	else if (arg->lflags->z)
		ft_putstr(ft_itoa((size_t)data)); // <---------- z flag ---------------
	else
		ft_putstr(ft_itoa((int)data));
}

static void ft_print_arg_u(t_arg *arg, va_list ap)
{
	unsigned long long	data;

	data = va_arg(ap, unsigned long long);
	if (arg->lflags->ll)
		ft_putstr(ft_itoa(data));
	else if (arg->lflags->l)
		ft_putstr(ft_itoa((unsigned long)data));
	else if (arg->lflags->h)
		ft_putstr(ft_itoa((unsigned short)data));
	else if (arg->lflags->hh)
		ft_putstr(ft_itoa((unsigned char)data));
	else if (arg->lflags->j)
		ft_putstr(ft_itoa((uintmax_t)data));
	else if (arg->lflags->z)
		ft_putstr(ft_itoa((size_t)data));
	else
		ft_putstr(ft_itoa((unsigned int)data));
}

static void	ft_print_arg_c(t_arg *arg, va_list ap)
{
	wint_t	data;

	data = va_arg(ap, wint_t);
	if (arg->lflags->l + arg->lflags->ll)
		ft_putchar(data);
	else
		ft_putchar((unsigned char)data);
}

static void	ft_print_arg_s(t_arg *arg, va_list ap)
{
	wchar_t	*data;

	data = va_arg(ap, wchar_t *);
	if (arg->lflags->l + arg->lflags->ll)
		ft_putstr(data);
	else
		ft_putstr((char *)data);
}

static void	ft_print_arg(t_arg *arg, va_list ap)
{
	if (arg->conv == 'd' || arg->conv == 'i')
		ft_print_arg_i(arg, ap);
	else if (arg->conv == 'o' || arg->conv == 'u' ||
		arg->conv == 'x' || arg->conv == 'X')
		ft_print_arg_u(arg, ap);
	else if (arg->conv == 'c' || arg->conv == 'C')
		ft_print_arg_c(arg, ap);
	else if (arg->conv == 's' || arg->conv == 'S')
		ft_print_arg_s(arg, ap);
}

void		ft_print(va_list *ap, char *format, t_list *args)
{
	int 	i;

	i = -1;
	while (format[++i])
	{
		if (format[i] != '%')
			ft_putchar(format[i]);
		else
		{
			ft_print_arg((t_arg *)args->content, ap);
			args = args->next;
		}
	}
}
