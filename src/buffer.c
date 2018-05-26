
#include "../printf.h"

t_buf	*ft_bufnew(char *buf_ptr)
{
	t_buf	*buf;

	if (!(buf = malloc(sizeof(t_buf))))
		return (NULL);
	buf->i = 0;
	buf->res = 0;
	buf->str = buf_ptr;
	return (buf);
}

void	ft_putbuf(t_buf *buf, int len)
{
	buf->res += buf->i;
	write(1, buf->str, len);
	ft_bzero(buf->str, len);
	buf->i = 0;
}

void	ft_putchar_buf(t_buf *buf, char c)
{
	buf->str[buf->i] = c;
	++(buf->i);
	if (buf->i == BUFF_SIZE)
		ft_putbuf(buf, BUFF_SIZE);
}

void	ft_putstr_buf(t_buf *buf, char *str)
{
	int		i;
	
	i = 0;
	while (str[i])
		ft_putchar_buf(buf, str[i++]);
}
