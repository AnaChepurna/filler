#include "../filler.h"

int		check_place(t_map *map, t_map *piece, t_board *board, char player)
{
	int		x;
	int		y;
	//ft_putendl_fd("check", 2);

	if (board->y_place + piece->y > map->y || board->x_place + piece->x > map->x)
		return (0);
	y = -1;
	while (++y < piece->y)
	{
		x = -1;
		while (++x < piece->x)
		{
			if (piece->map[y][x] == '*')
			{
				if (map->map[y + board->y_place][x + board->x_place] == P1 - 32
					|| map->map[y + board->y_place][x + board->x_place] == P1)
					return (player == P1 ? 1 : 0);
				if (map->map[y + board->y_place][x + board->x_place] == P2 - 32
					|| map->map[y + board->y_place][x + board->x_place] == P2)
					return (player == P2 ? 1 : 0);
			}
		}
	}
	return (0);
}

void	get_start_positions(t_board *board, t_map *map, char player)
{
	static int	n = 0;
	int			x;
	int			y;

	ft_putendl_fd("get start", 2);

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
				if (player == P1)
				{
					board->y_start_player = y;
					board->x_start_player = x;
				}
				else
				{
					 board->y_start_rival = y;
					 board->x_start_rival = x;
				}
			}
			if (map->map[y][x] == P2 || map->map[y][x] == P2 - 32)
			{
				if (player == P2)
				{
					board->y_start_player = y;
					board->x_start_player = x;
				}
				else
				{
					 board->y_start_rival = y;
					 board->x_start_rival = x;
				}
			}
		}
	}
}