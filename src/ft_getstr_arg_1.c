
//
// Created by Dimon on 07.04.2018.
//

#include "../printf.h"

char		*ft_getstr_arg_p(t_arg *arg, va_list *ap)
{
	void	*data;
	char	*str;
	char	*to_free;

	(void)arg;
	data = va_arg(*ap, void *);
	str = ft_uitoa_base((unsigned long long)data, 16);
	arg->flags |= F_SHARP;
	to_free = str;
	str = ft_strmap(str, (char (*)(char))ft_tolower);
	free(to_free);
	return (str);
}
