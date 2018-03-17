//
// Created by Dimon on 17.03.2018.
//

#ifndef ITOA_BASIC_H

# define ITOA_BASIC_H

/*
**	function ft_itoa_basic is strongly NOT recommended for straight usage,
**	because all validation is placed in "wrapping" functions, which are
**	recommended to use: ft_itoa, ft_itoa_base, ft_uitoa, ft_uitoa_base;
**	otherwise, in case of not valid arguments, undefined behavior is expected
*/

char	*ft_itoa_basic(unsigned long long num, int sign, int base);

#endif
