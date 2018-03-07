/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:34:31 by domelche          #+#    #+#             */
/*   Updated: 2018/03/07 20:07:54 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

// debug

void	ft_print_arg(t_arg *arg)
{
	printf("\n{\n\tflags:\n\t{\n\t\t'#': %d\n\t\t'0': %d\n\t\t'-': %d\n\t\t'+': %d\n\t\t' ': %d\n\t}\n\twidth: %d\n\tprecision: %d\n\tlength flags:\n\t{\n\t\tl: %d\n\t\tll: %d\n\t\th: %d\n\t\thh: %d\n\t\tj: %d\n\t\tz: %d\n\t}\n\tconversion: %c\n}\n\n",
			arg->flags->sharp, arg->flags->zero, arg->flags->minus,
			arg->flags->plus, arg->flags->space, arg->width, arg->prec,
			arg->lflags->l, arg->lflags->ll, arg->lflags->h, arg->lflags->hh,
			arg->lflags->j, arg->lflags->z, arg->conv);
}

// *****

t_arg	*ft_argnew()
{
	t_arg	*arg;

	arg = ft_smemalloc(sizeof(t_arg), "ft_argnew");
	arg->flags = ft_flagnew();
	arg->width = 0;
	arg->prec = 0;
	arg->lflags = ft_lflagnew();
	arg->conv = 0;
	return (arg);
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

int		ft_parse_lflags(char *str, t_arg *arg)
{
	if (*str == 'l')
	{
		if (*(str + 1) == 'l')
			return ((arg->lflags->ll = 1) + 1);
		else
			return ((arg->lflags->l = 1));
	}
	else if (*str == 'h')
	{
		if (*(str + 1) == 'h')
			return ((arg->lflags->hh = 1) + 1);
		else
			return ((arg->lflags->h = 1));
	}
	else if (*str == 'j')
		return ((arg->lflags->j = 1));
	else if (*str == 'z')
		return ((arg->lflags->z = 1));
	else
		return (0);
}

t_arg	*ft_parse_arg(char *str, int *index)
{
	t_arg	*arg;
	int		i;
	char	*res;

	arg = ft_argnew();
	i = ft_parse_flags(str, arg);
	*index += i;
	str += i;
	arg->width = ft_atoi(str);
	if ((res = ft_strchr(str, '.')))
	{
		str = res + 1;
		arg->prec = ft_atoi(str);
	}
	while (ft_isdigit(*str))
		++str;
	str += ft_parse_lflags(str, arg);
	arg->conv = *str;
	return (arg);
}

t_list	*ft_get_args(char *format)
{
	t_list	*args;
	int		i;

	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
			ft_lstpush(&args,
						ft_nodenew(ft_parse_arg(&format[i + 1],
												&i),
									sizeof(t_arg)));
	}
	return (args);
}

int		main(void)
{
	t_arg	*arg;
	int		i = 0;

	arg = ft_parse_arg("-0 +0 + #-0-0 +#78.98lli", &i);
	ft_print_arg(arg);
	return (1);
}
