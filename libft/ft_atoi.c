/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 18:49:36 by domelche          #+#    #+#             */
/*   Updated: 2017/10/26 18:49:38 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_atoi_cut(char *str, int *sign)
{
	int		i;
	int		j;
	char	*s;
	char	*res;

	i = 0;
	s = ft_strdup(str);
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	*sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] == '0')
		i++;
	j = i;
	while (ft_isdigit(s[j]) != 0 && s[j])
		j++;
	s[j] = 0;
	res = ft_strdup(&s[i]);
	free(s);
	return (res);
}

int			ft_atoi(const char *str)
{
	char				*s;
	int					sign;
	int					str_len;
	unsigned long long	res;
	size_t				i;

	res = 0;
	s = ft_atoi_cut((char *)str, &sign);
	str_len = ft_strlen(s);
	i = 0;
	while (s[i])
		res = res * 10 + (s[i++] - '0');
	free(s);
	if ((res > ATOI_ULL_MAX || str_len > 19) && sign > 0)
		return (-1);
	if ((res > ATOI_ULL_MAX || str_len > 19) && sign < 0)
		return (0);
	return ((int)(res * sign));
}
