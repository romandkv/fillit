#include "fillit.h"

void	free_map(t_map *m)
{
	int i;

	i = 0;
	while (i < m->size)
	{
		ft_memdel((void **)&(map->ar[i]));
		i++;
	}
	ft_memdel((void **)&map->ar);
	ft_memdel((void **)&m);
}

void	print_map(t_map *m)
{
	int i;

	i = 0;
	while (i < m->size)
	{
		ft_putstr(m->ar[i]);
		ft_putchar('\n');
		i++;
	}
}

t_map	*new_m(int size)
{
	t_map	*map;
	int	i;
	int	j;

	map = (t_map)malloc(sizeof(t_map));
	map->size = size;
	map->ar = (char **)malloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		map->ar[i] = (char *)malloc(sizeof(char) * size);
		j = 0;
		while (j < size)
		{
			map->ar[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

void	place_t(t_tetr *tetr, t_map *m, t_point *p, char ch)
{
	int i;
	int j;
	
	i = 0;
	while (i < tetr->h)
	{
		j = 0;
		while (j < tetr->w)
		{
			if (tetr->pos[i][j] == '#')
				m->ar[i + y][j + x] = ch;
			j++;
		}
		i++;
	}
	ft_memdel((void **)&p);
}

int	is_place(t_tetr *tetr, t_map *map, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < tetr->h)
	{
		j = 0;
		while (j < tetr->w)
		{
			if (tetr->pos[i][j] == '#' && map->ar[i + y][j + x] != '.')
				return (0);
		}
		i++;
	}

	return (1);
}


