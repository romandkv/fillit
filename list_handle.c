#include "fillit.h"
#include "gnl/get_next_line.h"

void push(char *line, t_tetro *list)
{
    t_tetro *new;

    new = (t_tetro*)malloc(sizeof(t_tetro));
    new->line = ft_strdup(line);
    new->next = NULL;
    list->next = new;
}