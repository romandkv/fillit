#include "fillit.h"

int	check_size(t_tetr t)
{
	int i;
	int count;

	i = 0;
	while (t.buff[i])
	{
		if (t.buff[i] == '#')
			count++;
		if (t.buff[i] != '#' || t.buff[i] != '.')
			return (0);
		i++;
	}
	return (i == 16 ? 1 : 0 && count == 4);
}

int	checker(char *buff, int i)
{
	int count;
	int size;

	size = ft_strlen(buff);
	count = 0;
	if (buff[i + 1] == '#' && i + 1 != size)
		count++;
	if (buff[i - 1] == '#' && i - 1 > -1)
		count++;
	if (buff[i + 4] == '#' && i + 4 != size)
		count++;
	if (buff[i - 4] == '#' && i - 4 > -1)
		count++;
	return (count);

}

int	check_connect(t_tetr t)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (t.buff[i])
	{
		if (t.buff[i] != '#')
			i++;
		else
		{
			count += checker(t.buff, i);
			i++;
		}
	}
	return (count == 6 || count == 8);
}

int	check_all(t_tetr *t)
{
	t_tetr *temp;

	temp = t;
	while (temp)
	{
		if (!(check_connect(*temp) && check_size(*temp)))
			return (0);
		temp = temp->next;
	}
	return (1);
}
