
#include "printf.h"

int 	main(void)
{
	char	*format = "unix -> %o\n";
	char	*ft_format;
	unsigned int 	d = UINT_MAX + 1;
	char	*s = "pisos";
	char	c = 0;

	int 	ret;

	ft_format = ft_strdup(format);
	ft_strncpy(ft_format, "mine", 4);

	ret = ft_printf(ft_format, d);
	ft_printf("(%d)\n", ret);
	ret = printf(format, d);
	printf("(%d)\n", ret);
	return (0);
}
