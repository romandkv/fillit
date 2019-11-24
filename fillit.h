#ifndef FILLIT_H
#define FILLIT_h

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft/libft.h"
typedef struct		s_tetr
{
	char		*buff;
	struct s_tetr	*next;
}			t_tetr;

int     check_all(t_tetr *t);
t_tetr  *get_tetr(int fd);
void    concat(char *buff, t_tetr *t);
t_tetr  *new(char *buff);
int     get_next_line(const int fd, char **line);
#endif
