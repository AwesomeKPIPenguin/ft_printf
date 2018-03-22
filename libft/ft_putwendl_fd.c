//
// Created by Dimon on 17.03.2018.
//

#include "libft.h"

void	ft_putwendl_fd(const wchar_t *wstr, int fd)
{
	ft_putwstr_fd(wstr, fd);
	ft_putchar_fd('\n', fd);
}
