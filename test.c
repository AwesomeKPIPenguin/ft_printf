
#include "stdio.h"
#include "printf.h"
#include <limits.h>
#include <locale.h>

int		main(void)
{
	setlocale(LC_ALL, "");

	char	*str = "PISOS";
	//wchar_t	*wstr = L"\u0680\u0681\u0682\u0683";

	printf("%10s\n", str);
	ft_printf("%10s\n", str);
	
	return (0);
}
