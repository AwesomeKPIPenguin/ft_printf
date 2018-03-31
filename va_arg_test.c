
#include "printf.h"

static void	ft_va_arg_test(int arg_0, ...)
{
	va_list 	ap;
	long long	arg;

	va_start(ap, arg_0);
	for (int i = 0; i < 3; i++)
	{
		arg = va_arg(ap, long long);
		printf("%lld\n", arg);
	}
	va_end(ap);
}

//int 		main(void)
//{
//	ft_va_arg_test(0, 1, 2, 3);
//	return (0);
//}
