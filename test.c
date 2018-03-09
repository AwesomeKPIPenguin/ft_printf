
#include "printf.h"
#include "stdio.h"
#include <limits.h>

void	ft_args(int arg0, ...)
{
	va_list	ap;
	//var		arg;
	int		arg;

	va_start(ap, arg0);
	for (int i = 0; i < 5; i++)
	{
		arg = va_arg(ap, int);
		printf("%d\n", arg);
	}
	va_end(ap);
}

int		main(void)
{
	//ft_args(0, 1, 2, 3, 4);
	printf("%+05lq", 1.123456789f);
	return (0);
}
