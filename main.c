#include "fillit.h"

int	main(int argc, char **argv)
{
	t_list	*list;
	t_map	*map;

	if (argc != 2)
		return (0);
	if (l(ist = reader(open(argv[1], O_RDONLY))) == NULL)
		return (1);
	map = solve(list);
	print_map(map);
	free_map(map);
	free_list(list);
	return (0);
}
