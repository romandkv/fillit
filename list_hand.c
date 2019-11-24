#include "fillit.h"
#include "libft/libft.h"

void	concat(char *buff, t_tetr *t)
{
	char *temp;

	temp = ft_strjoin(t->buff, buff);
	free(t->buff);
	t->buff = temp;
	free(buff);
}

t_tetr	*new(char *buff)
{
	t_tetr *tetr;

	tetr = (t_tetr *)malloc(sizeof(t_tetr));
	ft_strcpy(tetr->buff, buff);
	free(buff);
	tetr->next = NULL;
	return (tetr);
}
