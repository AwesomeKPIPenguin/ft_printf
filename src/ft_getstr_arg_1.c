
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
	if (!data && !arg->prec)
		*str = 0;
	return (str);
}

static void ft_getprec_for_ls(t_arg *arg, char *str)
{
	int 	i;
	int		new_prec;

	if (arg->prec < 1)
		return ;
	i = -1;
	new_prec = arg->prec;
	while (str[++i] && arg->prec > 0)
	{
		if ((unsigned char)str[i] < 0x80 || (unsigned char)str[i] >= 0xC0)
			--arg->prec;
		else
			++new_prec;
	}
	while ((unsigned char)str[i] >= 0x80 && (unsigned char)str[i] < 0xC0)
	{
		++new_prec;
		++i;
	}
	arg->prec = new_prec;
}

char		*ft_getstr_arg_s(t_arg *arg, va_list *ap)
{
	wchar_t	*data;
	char	*res;
	int 	len;

	data = va_arg(*ap, wchar_t *);
	if (!data)
		res = ft_strdup("(null)");
	else if ((arg->lflags & LF_L) | (arg->lflags & LF_LL))
	{
		res = ft_ustos(data);
		ft_getprec_for_ls(arg, res);
	}
	else
		res = ft_strdup((char *)data);
	len = ft_strlen(res);
	if (arg->prec < len && arg->prec != -1)
		res[arg->prec] = 0;
	return (res);
}
