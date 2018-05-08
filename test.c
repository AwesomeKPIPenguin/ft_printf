//
// Created by Dmytro OMELCHENKO on 5/5/18.
//

#include "printf.h"
#include <locale.h>
#include <stdio.h>

int		main(void)
{
	int		ret = 0;
	int		i = 0;

	//setlocale(LC_ALL, "");
//	while (++i < 300)
//	{
		ret = ft_printf("%s, %s, %s;\n", "pisos", "moi", "bolshoi");
		printf("(%d)\n", ret);
		ret = printf("unix: %C\n", 240);
		printf("(%d)\n", ret);
	//}
	return (0);
}
