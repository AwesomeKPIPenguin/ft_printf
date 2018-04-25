
#include "printf.h"
#include <locale.h>

int 	main(void)
{
	char	*format = "unix: %.4S";
	char	*ft_format;
	unsigned int 	d = 1;
	char	*s = "pisos";
	char	c = 'Z';

	int 	ret;

	setlocale(LC_ALL, NULL);

	ft_format = ft_strdup(format);
	ft_strncpy(ft_format, "mine", 4);

	ret = ft_printf(ft_format, L"他妈的长颈鹿");
	ft_printf("(%d)\n", ret);
	wchar_t *ws = malloc(12);
	ft_memmove(ws, L"他妈的长颈鹿", 12);
	ret = printf("unix: %ls\n", ws);
	printf("(%d)\n", ret);
	return (0);
}
