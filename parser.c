#include "fillit.h"

t_tetr	*get_tetr(int fd)
{
	char	*buff;
	t_tetr	*t;
	int	i;

	i = 1;
	get_next_line(fd, &buff);
	t = new(buff);
	while (get_next_line(fd, &buff))
	{
		concat(buff, t);
		i++;
		printf("%d\n", i);
		if (i == 4)
		{
			i = 0;
			t->next = new("");
			t = t->next;
		}
	}
	free(buff);
	return (t);	
}
