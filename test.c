
#include "printf.h"
#include <locale.h>

int 	main(void)
{
	char	*format = "unix: %.p, %.0p\n";
	char	*ft_format;
	unsigned int 	d = 0;
	char	*s = "pisos";
	char	c = 'P';

	int 	ret;

	setlocale(LC_ALL, NULL);

	ft_format = ft_strdup(format);
	ft_strncpy(ft_format, "mine", 4);

	ret = ft_printf(ft_format, d, d);
	ft_printf("(%d)\n", ret);
	ret = printf(format, d, d);
	printf("(%d)\n", ret);
	return (0);
}
