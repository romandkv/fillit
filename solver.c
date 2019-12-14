#include "fillit.h"

int	solve_m(t_map *m, t_list *list)
{
	int	x;
	int	y;
	t_tetr	*tetr;

	if (list == NULL)
		return (1);
	y = 0;
	tetr = (t_tetr *)list->content;
	while (y < m->size - tetr->h + 1)
	{
		x = 0;
		while (x < m->size - tetr->w + 1)
		{
			if (is_place(tetr, map, x, y))
			{
				if (solve_m(map, list->next))
					return (1);
				else
					place_t(tetr, map, new_p(x, y), '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	min_size(int size)
{
	int res;

	res = 2;
	while (res *res < size)
		res++;
	return (res);
}

t_map	*solve(t_list *list)
{
	t_map	*m;
	int	size;
	size = min_size(ft_lstcount(list) * 4);
	map = new_m(size);
	while (!solve_m(map, list))
	{
		size++;
		free_map(map);
		map = new_m(size);
	}
	return (map);
}
