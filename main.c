#include "fillit.h"

int	main(int argc, char **argv)
{
	t_tetr *t;
	int fd;

	if (argc != 2)
		return (-1);
	if (!(fd = open(argv[1], O_RDONLY)))
		return (-1);
	t = get_tetr(fd);
	check_all(t);
}
