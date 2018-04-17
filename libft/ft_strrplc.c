//
// Created by Dimon on 17.04.2018.
//

#include "libft.h"

void	ft_strrplc(char *str, char find, char put)
{
	if (!str)
		return ;
	while (*str)
	{
		if (*str == find)
			*str = put;
		++str;
	}
}
