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
	printf("\n{\n\tflags:\n\t{\n\t\t'#': %d\n\t\t'0': %d\n\t\t'-': %d\n\t\t'+':\
%d\n\t\t' ': %d\n\t}\n\twidth: %d\n\tprecision: %d\n\tlength flags:\n\t{\n\t\tl\
: %d\n\t\tll: %d\n\t\th: %d\n\t\thh: %d\n\t\tj: %d\n\t\tz: %d\n\t}\n\tconversio\
n: %c\n}\n\n",
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

void	ft_argdel(t_arg *arg)
{
	free(arg->flags);
	free(arg->lflags);
	free(arg);
}

int		ft_isvalid_conv(char conv)
{
	return ((conv == 's' || conv == 'S' || conv == 'p' || conv == 'd' ||
			conv == 'D' || conv == 'i' || conv == 'o' || conv == 'O' ||
			conv == 'u' || conv == 'x' || conv == 'X' || conv == 'c' ||
			conv == 'C') ? 1 : 0);
}

t_arg	*ft_parse_arg(char *str, int *to_cut)
{
	t_arg	*arg;
	int		i;

	arg = ft_argnew();
	i = 0;
	i += ft_parse_flags(str, arg);
	arg->width = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]))
		++i;
	if (str[i] == '.')
		arg->prec = ft_atoi(&str[++i]);
	while (ft_isdigit(str[i]))
		++i;
	i += ft_parse_lflags(&str[i], arg);
	if (ft_isvalid_conv(str[i]))
		arg->conv = str[i];
	else
	{
		ft_argdel(arg);
		return (NULL);
	}
	*to_cut = i;
	return (arg);
}

char	*ft_create_args_list(t_list **list, char *format)
{
	t_arg	*arg;
	char 	*to_remove;
	int		i;
	int 	to_cut;
	
	*list = NULL;
	i = -1;
	while (format[++i])
	{
//		printf("%c\n", format[i]);
		if (format[i] == '%')
		{
			if (!(arg = ft_parse_arg(&format[++i], &to_cut)))
				return (NULL);
			to_remove = format;
			format = ft_strcut(format, i, i + to_cut);
			free(to_remove);
//			printf("format: %s\n", format);
			ft_lstpush(list, ft_nodenew(arg, sizeof(t_arg)));
//			printf("left from [i]: %s\n", &format[i]);
		}
	}
	return (format);
}

//int		main(void)
//{
//	//int			i;
//	t_list	*args;
//	char	*str = ft_strdup("Hello, %i, Pisos! %#0+-125.455432jS, %d, %010.2X");
//	//i = 0;
//	//ft_print_arg(ft_parse_arg("#-+010.3lhllhld", &i));
//	//printf("i: %d\n", i);
//	str = ft_create_args_list(&args, str);
//	ft_print_args(args);
//	printf("str: %s\n", str);
//
//	return (1);
//}
