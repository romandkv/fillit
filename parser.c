#include <fcntl.h>
#include "gnl/get_next_line.h"

void    get_tetrino(char *buff, char *line)
{
    char *tmp;

    if (!*line)
        line = ft_strnew(1);
    tmp = strjoin(line, buff);
    free(line);
    free(buff);
    line = tmp;
}

char    *get_list_tetrino(int fd)
{
    char *buff;
    char *line;
    int count;
    int flag;

    count = 0;
    while (flag = get_next_line(fd, &buff))
    {
        if (count == 4)
        {
            break;
        }
        get_tetrino(buff, line);
        count++;
    }
    if (flag == 0)
        return (NULL);
    return (line);
}

int     parser(const char *filename)
{
    int fd;
    char *buff;
    char *line;
    t_tetro *list;

    tetro = ft_strnew(1);
    fd = open(filename, O_RDONLY);
    while (line = get_list_tetrino(fd))
    {
        push(line, list);

    }
}