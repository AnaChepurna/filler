#include "../filler.h"

int main(int argc, char const *argv[])
{
	t_map *map;

	(void)argv;
	(void)argc;
	map = get_map();

	int i = 0;
	while (i < map->y)
	{
		ft_putendl(map->map[i]);
		i++;
	}
	clear_map(&map);
	//ft_putstr("0 0");
	return 0;
}