
#include "stdio.h"
#include "printf.h"
#include <limits.h>
#include <locale.h>

int		main(void)
{
	//setlocale(LC_ALL, "");
	wprintf("%10S\n", L"ファックキリン");
//	ft_printf("%+.10i\n", -12324);
	return (0);
}
