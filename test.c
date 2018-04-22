
#include "printf.h"
#include <locale.h>

int 	main(void)
{
	char	*format = "unix: {%05.c}\n";
	char	*ft_format;
	unsigned int 	d = 35;
	char	*s = "pisos";
	char	c = 'Z';

	int 	ret;

	setlocale(LC_ALL, NULL);

	ft_format = ft_strdup(format);
	ft_strncpy(ft_format, "mine", 4);

	ret = ft_printf(ft_format, c);
	ft_printf("(%d)\n", ret);
	ret = printf(format, c);
	printf("(%d)\n", ret);
	return (0);
}
