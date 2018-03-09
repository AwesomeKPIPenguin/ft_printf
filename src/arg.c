/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:34:31 by domelche          #+#    #+#             */
/*   Updated: 2018/03/09 18:04:18 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

// debug

void	ft_print_arg(t_arg *arg)
{
	if (!arg)
	{
		printf("\n(null)\n\n");
		return ;
	}
	printf("\n{\n\tflags:\n\t{\n\t\t'#': %d\n\t\t'0': %d\n\t\t'-': %d\n\t\t'+': %d\n\t\t' ': %d\n\t}\n\twidth: %d\n\tprecision: %d\n\tlength flags:\n\t{\n\t\tl: %d\n\t\tll: %d\n\t\th: %d\n\t\thh: %d\n\t\tj: %d\n\t\tz: %d\n\t}\n\tconversion: %c\n}\n\n",
			arg->flags->sharp, arg->flags->zero, arg->flags->minus,
			arg->flags->plus, arg->flags->space, arg->width, arg->prec,
			arg->lflags->l, arg->lflags->ll, arg->lflags->h, arg->lflags->hh,
			arg->lflags->j, arg->lflags->z, arg->conv);
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

int		ft_isvalid_conv(char conv)
{
	return ((conv == 's' || conv == 'S' || conv == 'p' || conv == 'd' ||
			conv == 'D' || conv == 'i' || conv == 'o' || conv == 'O' ||
			conv == 'u' || conv == 'x' || conv == 'X' || conv == 'c' ||
			conv == 'C') ? 1 : 0);
}

t_arg	*ft_parse_arg(char *str, int *index)
{
	t_arg	*arg;
	int		i;
	int		res;

	arg = ft_argnew();
	i = 0;
	i += ft_parse_flags(str, arg);
	arg->width = ft_atoi(&str[i]);
	if ((res = ft_indexof_chr(&str[i], '.')) != -1)
	{
		i += res + 1;
		arg->prec = ft_atoi(&str[i]);
	}
	while (ft_isdigit(str[i]))
		++i;
	i += ft_parse_lflags(&str[i], arg);
	if (ft_isvalid_conv(str[i]))
		arg->conv = str[i];
	else
		return (NULL);
	*index += i + 2;
	return (arg);
}

t_list	*ft_get_args(char *format)
{
	t_list	*args;
	t_arg	*arg;
	int		i;
	
	args = NULL;
	i = -1;
	while (format[++i])
	{
		printf("%c\n", format[i]);
		if (format[i] == '%')
		{
			if (!(arg = ft_parse_arg(&format[i + 1], &i)))
				return (NULL);
			ft_lstpush(&args, ft_nodenew(arg, sizeof(t_arg)));
			printf("i: %s\n", &format[i]);
		}
	}
	return (args);
}

int		main(void)
{
	int			i;
	//t_list	*args;
	i = 0;
	ft_print_arg(ft_parse_arg("d", &i));
	printf("i: %d\n", i);
	//args = ft_get_args("Hello, %i, Pisos! %#0+-125.4554332jS, %d, %010.2X");
	//ft_print_args(args);
	return (1);
}
