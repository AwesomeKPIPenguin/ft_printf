/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:06:48 by domelche          #+#    #+#             */
/*   Updated: 2018/04/13 16:07:52 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static void ft_strjoin_3(char *dst, char *str_0, char *str_1, char *str_2)
{
	int 	i;

	i = 0;
	if (str_0)
	{
		ft_strcpy(dst, str_0);
		i += ft_strlen(str_0);
		free(str_0);
	}
	if (str_1)
	{
		ft_strcpy(&(dst[i]), str_1);
		i += ft_strlen(str_1);
		free(str_1);
	}
	if (str_2)
	{
		ft_strcpy(&(dst[i]), str_2);
		//free(str_2);//              <--------------------- weird free --------
	}
}

static char *ft_get_sharp_str(t_arg *arg, int *sharp_len)
{
	char	*sharp_str;

	sharp_str = NULL;
	*sharp_len = 0;
	if (arg->flags & F_SHARP)
	{
		sharp_str = (arg->conv == 'o') ? ft_strdup("0") : ft_strdup("0X");
		if (arg->conv == 'x' || arg->conv == 'p')
			sharp_str[1] = 'x';
		*sharp_len = ft_strlen(sharp_str);
	}
	return (sharp_str);
}

/*
**	str[0] - resulting string;
**	str[1] - sharp string;
**	str[2] - padding string;
**
**	len[1 - 3] - length of each string respectively;
*/

char		*ft_handle_width(t_arg *arg, char *s)
{
	char	*str[3];
	int 	len[3];
	char	fill_char;

	str[0] = s;
	len[0] = ft_strlen(s);
	str[1] = ft_get_sharp_str(arg, &(len[1]));
	str[2] = NULL;
	len[2] = (arg->width > len[0] + len[1]) ? arg->width - len[0] - len[1] : 0;
	if (len[2] > 0 || str[1])
	{
		fill_char = (arg->flags & F_ZERO) ? '0' : ' ';
		if (!(str[0] = malloc((len[0] + len[2] + len[1] + 1) * sizeof(char))))
			return (NULL);
		if (len[2] != 0)
			if (!(str[2] = ft_strnew(len[2], fill_char)))
				return (NULL);
		if (str[2] && *str[2] == '0')
			ft_strjoin_3(str[0], str[1], str[2], s);
		else if (arg->flags & F_MINUS)
			ft_strjoin_3(str[0], str[1], s, str[2]);
		else
			ft_strjoin_3(str[0], str[2], str[1], s);
	}
	return (str[0]);
}

char		*ft_handle_prec(t_arg *arg, char *str)
{
	char	*res;
	int		len;
	int		sign;

	len = ft_strlen(str);
	sign = (*str == '-') ? 1 : 0;
	if (!(F_ZERO & ft_getmask(arg->conv)) || arg->conv == 'c' ||
		arg->conv == 's' || arg->conv == '%' || arg->prec <= len - sign)
		return (str);
	if (!(res = malloc((arg->prec + sign) * sizeof(char))))
		return (NULL);
	ft_memset(&(res[sign]), '0', arg->prec - len + sign);
	(void)(ft_strcpy(&(res[2 * sign + arg->prec - len]), &(str[sign])) -
		   arg->prec + len);
	if (sign)
		res[0] = '-';
	free(str);
	return (res);
}

char		*ft_handle_plus(t_arg *arg, char *str)
{
	char	*res;

	if ((arg->flags & (F_PLUS | F_SPACE)) && *str != '-')
	{
		res = ft_strjoin((arg->flags & F_PLUS) ? "+" : " ", str);
		free(str);
		str = res;
	}
	return (str);
}
