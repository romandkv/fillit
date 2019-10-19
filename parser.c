#include <fcntl.h>

int     parser(const char *filename)
{
    int fd;
    char *buff;

    fd = open(filename, O_RDONLY);
    buff = (char *)malloc(21);

}