//
// Created by Dimon on 17.03.2018.
//

#include "libft.h"
#include "itoa_basic.h"

char		*ft_uitoa(unsigned long long num)
{
	return (ft_itoa_basic(num, 0, 10));
}
