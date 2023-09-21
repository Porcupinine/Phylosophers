
#include <stdlib.h>

static void	ft_bzero(void *s, size_t n)
{
	size_t	count;
	char	*alias;

	count = 0;
	alias = (char *) s;
	while (count < n)
	{
		alias[count] = '\0';
		count++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*call;

	call = malloc(count * size);
	if (call == NULL)
		return (NULL);
	ft_bzero(call, (count * size));
	return (call);
}