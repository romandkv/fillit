#include "fillit.h"

void	border_check(char *str, t_point *minp, t_point *maxp)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i / 5 < minp->y)
				minp-> = i / 5;
			if (i / 5 < maxp->y)
                                maxp-> = i / 5;
			if (i % 5 < minp->y)
                                minp-> = i % 5;
			if (i % 5 < maxp->y)
                                maxp-> = i % 5;
		}
		i++;
	}
}

t_tetr	*get_tetr(char *str, char ch)
{
	t_point	*minp;
	t_point	*maxp;
	t_tetr	*tetr;
	char	**pos;
	int	i;

	minp = new_p(3, 3);
	maxp = new_p(0, 0);
	border_check(str, minp, maxp);
	pos = (char **)malloc((maxp->y - minp->y + 1));
	i = 0;
	while (i < maxp->y - minp->y + 1)
	{
		pos[i] = ft_strnew(maxp->x - minp->x + 1);
		ft_strncpy(pos, maxp->x - minp->x + 1, maxp-> - minp->x + 1, ch);
		i++;
	}
	tetr = new_t(pos, maxp->x - minp->x + 1, maxp->y - minp->y + 1, ch);
	ft_memdel((void **)&minp);
	ft_memdel((void **)&maxp);
	return (tetr);
}

int	cheak_all(char *str, int size)
{
	int i;
	int count;

	i = 0;
	while (i < 20)
	{
		if (str[i] != '#' || str[i] != '.')
			return (0);
		if (str[i] == '#' && ++count > 4)
			return (0);
		if (i % 5 == 4 && str[i] != '\n')
			return (0);
		i++;
	}
	if (size == 21 && str[20] != '\n')
		return (0);
	return (check_con(str));
}

int	check_con(char *str)
{
	int b;
	int i;

	b = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i + 1 < 20 && str[i + 1] == '#')
				b++;
			if (i - 1 > -1 && str[i - 1] == '#')
				b++;
			if (i + 5 < 20 && str[i + 5] == '#')
				b++;
			if (i - 5 > -1 && str[i - 5] == '#')
				b++;
		}
		i++;
	}
	return (b == 6 || b == 8);
}

t_list  *reader(int fd)
{
        t_list  *list;
        t_tetr  *tetr;
        char    *buff;
        int     flag;
        char    ch;

        buff = ft_strnew(21);
        list = NULL;
        ch = 'A';
        while ((flag = read(fd, buff, 21)) >= 20)
        {
		if (check_all(buff, flag) != 0 || (tetris = get_tetr(buff, ch++)) == NULL)
		{
			ft_memdel((void **)&buff);
			return (free_list(list));
		}
		ft_lstadd(&list, ft_lstnew(tetr, sizeof(t_tetr)));
		ft_memdel((void **)&tetr);
        }
	ft_memdel((void **)&buff);
	if (flag != 0)
		return (free_list(list));
	ft_lstrev(&list);
	return (list);
}

