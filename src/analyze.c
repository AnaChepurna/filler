#include "../filler.h"


void	get_start_positions(t_board *board, t_map *map, char player)
{
	static int	n = 0;
	int			x;
	int			y;

	if (n++)
		return ;
	y = -1;
	while (++y < map->y)
	{
		x = -1;
		while (++x < map->x)
		{
			if (map->map[y][x] == P1 || map->map[y][x] == P1 - 32)
			{
				player == P1 ? board->y_start_player = y ? board->y_start_rival = y;
				player == P1 ? board->x_start_player = x ? board->x_start_rival = x;
			}
			if (map->map[y][x] == P2 || map->map[y][x] == P2 - 32)
			{
				player == P2 ? board->y_start_player = y ? board->y_start_rival = y;
				player == P2 ? board->x_start_player = x ? board->x_start_rival = x;

			}
		}
	}
}