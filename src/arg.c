/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:34:31 by domelche          #+#    #+#             */
/*   Updated: 2018/03/22 16:33:20 by domelche         ###   ########.fr       */
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

// *****

t_arg	*ft_argnew()
{
	t_arg	*arg;

	arg = ft_smemalloc(sizeof(t_arg), "ft_argnew");
	return (arg);
}

int		ft_get_conv(t_arg *arg, char conv)
{
	if (conv == 's' || conv == 'd' || conv == 'i' || conv == 'o' ||
		conv == 'u' || conv == 'x' || conv == 'X' || conv == 'c' ||
		conv == 'p')
		return (conv);
	else if (conv == 'D' || conv == 'C' || conv == 'S' || conv == 'O' ||
			conv == 'U')
	{
		arg->lflags |= LF_L;
		return (ft_tolower(conv));
	}
	return (0);
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
	arg->conv = ft_get_conv(arg, str[i]);
	if (!arg->conv)
	{
		free(arg);
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
		if (format[i] == '%')
		{
			if (!(arg = ft_parse_arg(&format[++i], &to_cut)))
				return (NULL);
			
			//printf("leftover: %s\n", &format[i]);
			//ft_print_arg(arg);
			
			to_remove = format;
			format = ft_strcut(format, i, i + to_cut);
			--i;
			free(to_remove);
			ft_lstpush(list, ft_nodenew(arg, sizeof(t_arg)));
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
