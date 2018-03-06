
#include "libft.h"

t_list	*ft_nodenew(void *content, size_t content_size)
{
	t_list	*node;

	node = ft_smemalloc(sizeof(t_list), "ft_nodenew");
	node->content = content;
	node->content_size = (content) ? content_size : 0;
	node->next = NULL;
	return (node);
}
