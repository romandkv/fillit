#include "fillit.h"

char	**gen_row(int size)
{
	char	**sol;
	int	i;
	int	j;

	sol = (char **)malloc(sizeof(char *) * size);
	i = 0;
	j = 0;
	while (i < size)
	{
		sol[i] = (char *)malloc(sizeof(char) * size);
		while (j < size)
		{
			sol[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	return (sol);
}


int	find_place(t_tetr t, char **row, int i, int j)
{
	int i;

	i = 0
	while (i < )
}

int	put_tetr(t_tetr t, char **row, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			if (row[i][j] != '.')
			{
			}
			j++;
		}
		j = 0;
		i++;
	}
}

char	**solve(t_tetr *list, int size)
{
	char	**row;
	t_tetr	*temp;

	temp = list;
	row = gen_row(size);
	while (temp)
	{
		temp = temp->next;
	}
}
