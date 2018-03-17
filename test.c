
#include "printf.h"
#include "stdio.h"
#include <limits.h>
#include <locale.h>

int		main(void)
{
	int 	base;

	printf("Zeroes:\n\n");
	printf("%s\n%s\n%s\n%s\n\n",
		   ft_itoa(0), ft_itoa_base(0, 2), ft_uitoa(0), ft_uitoa_base(0, 2));

	printf("Signed:\n\n");
	printf("%d -> %s\n", INT_MAX, ft_itoa(INT_MAX));
	printf("%d -> %s\n", INT_MIN, ft_itoa(INT_MIN));
	printf("%ld -> %s\n", LONG_MAX, ft_itoa(LONG_MAX));
	printf("%ld -> %s\n", LONG_MIN, ft_itoa(LONG_MIN));

	printf("\nUnsigned:\n\n");
	printf("%u -> %s\n", UINT_MAX, ft_uitoa(UINT_MAX));
	printf("%lu -> %s\n", ULONG_MAX, ft_uitoa(ULONG_MAX));

	printf("\nBases:\n\n");
	base = 1;
	while (++base < 17)
	{
		printf("1234567890 in base %d: %s\n",
			   base, ft_itoa_base(1234567890, base));
		printf("ULONG_MAX in base %d : %s\n\n",
			   base, ft_uitoa_base(ULONG_MAX, base));
	}
	return (0);
}
