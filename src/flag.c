
#include "../printf.h"

t_flag	*ft_flagnew()
{
	t_flag	*flags;

	flags = ft_smemalloc(sizeof(t_flag), "ft_flagnew");
	flags->sharp = 0;
	flags->zero = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->space = 0;
	return (flags);
}
