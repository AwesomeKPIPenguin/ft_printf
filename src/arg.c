
#include "../printf.h"

// debug

void	ft_print_arg(t_arg *arg)
{
	printf("\n{\n    flags:\n    {\n\t'#': %d\n\t'0': %d\n\t'-': %d\n\t'+': %d\n\t' ': %d\n    }\n    width: %d\n    precision: %d\n    length flags:\n    {\n\tl: %d\n\tll: %d\n\th: %d\n\thh: %d\n\tj: %d\n\tz: %d\n    }\n    conversion: %c\n}\n\n",
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
			return (i);
		i++;
	}
}

t_arg	*ft_parse_arg(char *str, int *index)
{
	t_arg	*arg;
	int		i;

	arg = ft_argnew();
	i = ft_parse_flags(str, arg);
	*index += i;
	str += i;
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
	t_arg *arg = ft_argnew();

	printf("%d\n", ft_parse_flags("-0#78.98lli", arg));
	ft_print_arg(arg);
	return (1);
}
