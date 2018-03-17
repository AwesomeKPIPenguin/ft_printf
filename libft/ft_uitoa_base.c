//
// Created by Dimon on 17.03.2018.
//

#include "libft.h"
#include "itoa_basic.h"

char		*ft_uitoa_base(unsigned long long num, int base)
{
	if (base < 2 || base > 16)
		return (NULL);
	return (ft_itoa_basic(num, 0, base));
}
