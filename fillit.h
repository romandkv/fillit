#ifndef FILLIT_H
#define FILLIT_H

typedef struct	s_point
{
	int	x;
	int	y;
}		t_point;

typedef struct	s_tetro
{
	char	**pos;
	char	c;
	int	w;
	int	h;
}		t_tetro;

typedef struct	s_map
{
	int	size;
	char	**ar;
}		t_map;

#endif
