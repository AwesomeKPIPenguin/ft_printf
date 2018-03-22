//
// Created by Dimon on 17.03.2018.
//

#include "libft.h"

void	ft_putwchar_fd(wint_t wc, int fd)
{
	char	u_char[4];

	ft_bzero(u_char, 4);
	if (wc < 0x80)
		u_char[0] = wc;
	else if (wc < 0x800)
	{
		u_char[0] = 0xC0 | ((0xFC0 & wc) >> 6);
		u_char[1] = 0x80 | (0x3F & wc);
	}
	else if (wc < 0x1000)
	{
		u_char[0] = 0xE0 | ((0xF000 & wc) >> 12);
		u_char[1] = 0x80 | ((0xFC0 & wc) >> 6);
		u_char[2] = 0x80 | (0x3F & wc);
	}
	else if (wc < 0x110000)
	{
		u_char[0] = 0xF0 | ((0x3C0000 & wc) >> 18);
		u_char[1] = 0x80 | ((0x3F000 & wc) >> 12);
		u_char[2] = 0x80 | ((0xFC0 & wc) >> 6);
		u_char[3] = 0x80 | (0x3F & wc);
	}
	ft_putstr_fd(u_char, fd);
}
