/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:06:48 by domelche          #+#    #+#             */
/*   Updated: 2018/05/05 14:59:39 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	ft_handle_left_pad(t_arg *arg)
{
	int		i;

	if ((arg->flags & F_ZERO) || (arg->flags & F_MINUS) || !arg->pad_len)
		return ;
	i = -1;
	while (++i < arg->pad_len)
		ft_putchar_buf(arg->buf, ' ');
}

void	ft_handle_sharp(t_arg *arg)
{
	char	sharp_str[3];

	if (arg->sign)
		ft_putchar_buf(arg->buf, arg->sign);
	if (!arg->sharp_len)
		return ;
	sharp_str[0] = '0';
	sharp_str[1] = 0;
	sharp_str[2] = 0;
	if (arg->conv != 'o')
		sharp_str[1] = arg->conv;
	ft_putstr_buf(arg->buf, sharp_str);
}

void	ft_handle_zero_pad(t_arg *arg)
{
	int		i;

	i = -1;
	if ((arg->flags & F_ZERO) && !(arg->flags & F_MINUS) && arg->pad_len)
		while (++i < arg->pad_len)
			ft_putchar_buf(arg->buf, '0');
	i = -1;
	while (++i < arg->prec_len)
		ft_putchar_buf(arg->buf, '0');
}

void	ft_handle_right_pad(t_arg *arg)
{
	int		i;

	if ((arg->flags & F_ZERO) || !(arg->flags & F_MINUS) || !arg->pad_len)
		return ;
	i = -1;
	while (++i < arg->pad_len)
		ft_putchar_buf(arg->buf, ' ');
}

void	ft_handle_flags(t_arg *arg)
{
	if (arg->conv == 's' || arg->conv == 'c')
		arg->prec_len = arg->prec;
	else
		arg->prec_len = (arg->prec > arg->data_len) ?
			arg->prec - arg->data_len : 0;
	if (arg->flags & F_SHARP)
		arg->sharp_len = (arg->conv == 'o') ? 1 : 2;
	if (arg->sign != '-')
	{
		if (arg->flags & F_SPACE)
			arg->sign = ' ';
		else if (arg->flags & F_PLUS)
			arg->sign = '+';
	}
	arg->pad_len = arg->width - arg->data_len - ((arg->sign) ? 1 : 0) -
		arg->sharp_len - arg->prec_len;
	arg->pad_len = (arg->pad_len < 0) ? 0 : arg->pad_len;
	ft_handle_left_pad(arg);
	ft_handle_sharp(arg);
	ft_handle_zero_pad(arg);
	if (arg->conv == 'c' && !*(arg->data))
		ft_putchar_buf(arg->buf, 0);
	else
		ft_putstr_buf(arg->buf,
			(arg->sign == '-') ? arg->data + sizeof(char) : arg->data);
	ft_handle_right_pad(arg);
}






//static void	ft_strjoin_3(char *dst, char *str_0, char *str_1, char *str_2)
//{
//	int		i;
//
//	i = 0;
//	if (str_0)
//	{
//		ft_strcpy(dst, str_0);
//		i += ft_strlen(str_0);
//		free(str_0);
//	}
//	if (str_1)
//	{
//		ft_strcpy(&(dst[i]), str_1);
//		i += ft_strlen(str_1);
//		free(str_1);
//	}
//	if (str_2)
//	{
//		ft_strcpy(&(dst[i]), str_2);
//		free(str_2);
//	}
//}
//
//static char	*ft_get_sharp_str(t_arg *arg, int *sharp_len)
//{
//	char	*sharp_str;
//
//	sharp_str = NULL;
//	*sharp_len = 0;
//	if (arg->flags & F_SHARP)
//	{
//		sharp_str = (arg->conv == 'o') ? ft_strdup("0") : ft_strdup("0X");
//		if (arg->conv == 'x' || arg->conv == 'p')
//			sharp_str[1] = 'x';
//		*sharp_len = ft_strlen(sharp_str);
//	}
//	return (sharp_str);
//}
//
///*
//**	str[0] - resulting string;
//**	str[1] - sharp string;
//**	str[2] - padding string;
//**
//**	len[1 - 3] - length of each string respectively;
//*/
//
//char		*ft_handle_width(t_arg *arg, char *s)
//{
//	char	*str[3];
//	int		len[3];
//	char	fill_char;
//
//	str[0] = s;
//	len[0] = ft_strlen(s);
//	str[1] = ft_get_sharp_str(arg, &(len[1]));
//	str[2] = NULL;
//	len[2] = (arg->width > len[0] + len[1]) ? arg->width - len[0] - len[1] : 0;
//	if (len[2] > 0 || str[1])
//	{
//		fill_char = (arg->flags & F_ZERO) ? '0' : ' ';
//		if (!(str[0] = malloc((len[0] + len[2] + len[1] + 1) * sizeof(char))))
//			return (NULL);
//		if (len[2] != 0)
//			if (!(str[2] = ft_strnew(len[2], fill_char)))
//				return (NULL);
//		if (str[2] && *str[2] == '0')
//			ft_strjoin_3(str[0], str[1], str[2], s);
//		else if (arg->flags & F_MINUS)
//			ft_strjoin_3(str[0], str[1], s, str[2]);
//		else
//			ft_strjoin_3(str[0], str[2], str[1], s);
//	}
//	return (str[0]);
//}
//
//char		*ft_handle_prec(t_arg *arg, char *str)
//{
//	char	*res;
//	int		len;
//	int		sign;
//
//	len = ft_strlen(str);
//	sign = (*str == '-') ? 1 : 0;
//	if (!(F_ZERO & ft_getmask(arg->conv)) || arg->conv == 'c' ||
//		arg->conv == 's' || arg->conv == '%' || arg->prec <= len - sign)
//		return (str);
//	if (!(res = malloc((arg->prec + sign) * sizeof(char))))
//		return (NULL);
//	ft_memset(&(res[sign]), '0', arg->prec - len + sign);
//	(void)(ft_strcpy(&(res[2 * sign + arg->prec - len]), &(str[sign])) -
//		arg->prec + len);
//	if (sign)
//		res[0] = '-';
//	free(str);
//	return (res);
//}
//
//char		*ft_handle_plus(t_arg *arg, char *str)
//{
//	char	*res;
//
//	if ((arg->flags & (F_PLUS | F_SPACE)) && *str != '-')
//	{
//		res = ft_strjoin((arg->flags & F_PLUS) ? "+" : " ", str);
//		free(str);
//		str = res;
//	}
//	return (str);
//}
