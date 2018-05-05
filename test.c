//
// Created by Dmytro OMELCHENKO on 5/5/18.
//

#include "printf.h"
#include <locale.h>
#include <stdio.h>

int		main(void)
{
	int		ret = 0;

	//setlocale(LC_ALL, "");
	ret = ft_printf("mine: %C\n", L'以');
	printf("(%d)\n", ret);
	ret = printf("%C", L'以');
	printf("(%d)\n", ret);
	return (0);
}
