//
// Created by Dimon on 17.03.2018.
//

#include "libft.h"

void	ft_putwstr_fd(const wchar_t *wstr, int fd)
{
	while (*wstr)
		ft_putwchar_fd(*(wstr++), fd);
}
