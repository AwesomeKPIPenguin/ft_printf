/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 13:40:13 by domelche          #+#    #+#             */
/*   Updated: 2018/03/31 18:07:29 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwchar_fd(wint_t wc, int fd)
{
	char	*str;
	int		size;

	size = 4;
	if (!(str = ft_wctoa(wc)))
		return ;
	while (!*str)
	{
		--size;
		++str;
	}
	write(fd, str, size);
	free(str);
}
