
#include "../printf.h"

t_lflag	*ft_lflagnew()
{
	t_lflag	*lflags;

	lflags = ft_smemalloc(sizeof(t_lflag), "ft_lflagnew");
	lflags->l = 0;
	lflags->ll = 0;
	lflags->h = 0;
	lflags->hh = 0;
	lflags->j = 0;
	lflags->z = 0;
	return (lflags);
}
