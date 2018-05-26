
#include <stdio.h>
#include "printf.h"

int		main(void)
{
	char	*str;

	str = (char *)malloc(3001);
	ft_memset((void *)str, 'A', 3000);
	str[3000] = 0;
	printf("%d\n", printf("unix: [%s]\n", str));
	printf("%d\n", ft_printf("mine: [%s]\n", str));
	return (0);
}
