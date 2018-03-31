
#include "stdio.h"
#include "printf.h"
#include <limits.h>
#include <locale.h>

int		main(void)
{
	setlocale(LC_ALL, "");
	
	wchar_t	*wstr = L"\u0680\u0681\u0682\u0683";

	printf("%S\n", wstr);
	wstr = (unsigned char *)wstr;
	for (int i = 0; i < 8; i++)
		printf("%hhd; ", wstr[i]);
	printf("\n");
	wstr = (wchar_t *)wstr;
	printf("%S\n", wstr);
//	ft_printf("%S\n", wstr);
	
	return (0);
}
