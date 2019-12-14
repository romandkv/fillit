#include "fillit.h"

t_point	*new_p(int x, int y)
{
	t_point *p;

	p = (t_point)malloc(sizeof(t_point));
	p->x = x;
	p->y = y;
	return (p);
}

t_tetr	*new_t(char *buff, int w, int h, char c)
{
	t_tetr *t;

	t = (t_tetr)malloc(sizeof(t_tetr));
	t->pos = buff;
	t->w = w;
	t->h = h;
	t->c = c;
	return (t);
}

void	free_list(t_list *list)
{
	t_list	*next;
	t_tetr	*tetr;

	while (list)
	{
		tetr = (t_tetr *)list->content;
		next = list->next;
		free_tetr(tetr);
		ft_memdel((void **)&list);
		list = next;

	}
}

void	free_tetr(t_tetr *t)
{
	int y;

	y = 0;
	while (y < tetri->height)
	{
		ft_memdel((void **)(&(t->pos[y])));
		y++;
	}
	ft_memdel((void **)(&(t->pos)));
	ft_memdel((void **)&t);
}
