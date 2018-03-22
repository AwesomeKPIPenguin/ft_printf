
#include "printf.h"
#include "stdio.h"
#include <limits.h>
#include <locale.h>

int		main(void)
{
	printf("printf: Nu %s, %c%c! %d, %o, %u, %x\n",
			"zdarova", 'h', 'u', 'i', 228, 228, 228, 228);
	ft_printf("ft_printf: Nu %s, %c%c! %d, %o, %u, %x\n",
			"zdarova", 'h', 'u', 'i', 228, 228, 228, 228);
	return (0);
}
