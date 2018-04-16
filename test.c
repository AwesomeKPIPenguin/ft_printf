
#include "printf.h"

int 	main(void)
{
	char	*format = "das ist% d;\n";
	int 	d = 42;
	char	*s = "pisos";
	char	c = NULL;

	ft_putendl("mine\n || \n \\/ \nright\n");
	ft_printf(format, d);
	printf(format, d);
	return (0);
}
