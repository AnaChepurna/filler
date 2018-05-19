#include "../filler.h"

int		check_place(t_map *map, t_map *piece, t_board *board, char player)
{
	int		x;
	int		y;
	int		n;

	if (board->y_place + piece->y > map->y || board->x_place + piece->x > map->x)
		return (0);
	n = 0;
	y = -1;
	while (++y < piece->y)
	{
		x = -1;
		while (++x < piece->x)
		{
			if (piece->map[y][x] == '*')
			{
				if (map->map[y + board->y_place][x + board->x_place] == player - 32
					|| map->map[y + board->y_place][x + board->x_place] == player)
					n++;
				if (map->map[y + board->y_place][x + board->x_place] == (RIVAL(player)) - 32
					|| map->map[y + board->y_place][x + board->x_place] == (RIVAL(player)))
					return (player == P2 ? 1 : 0);
			}
		}
	}
	return (n == 1 ? 1 : 0);
}

static int		is_near_rival(int x, int y, t_map *map,char player)
{
	char rival;

	rival = RIVAL(player);
	if (map->map[y][x + 3] == rival || map->map[y][x + 3] == rival - 32)
		return (1);
	if (map->map[y][x - 3] == rival || map->map[y][x - 3] == rival - 32)
		return (1);
	if (map->map[y + 3][x] == rival || map->map[y + 3][x] == rival - 32)
		return (1);
	if (map->map[y - 3][x] == rival || map->map[y - 3][x] == rival - 32)
		return (1);
	return (0);
}

int		check_rival(t_map *map, char player)
{
	int		x;
	int		y;

	y = 3;
	while (y < map->y)
	{
		x = 3;
		while (x < map->x)
		{
			if ((map->map[y][x] == player || map->map[y][x] == player - 32)
				&& is_near_rival(x, y, map, player))
				return (1);
			x++;
		}
		y++;
	}
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
			if (map->map[y][x] == player || map->map[y][x] == player - 32)
			{
				board->y_start_player = y;
				board->x_start_player = x;
			}
			if (map->map[y][x] == (RIVAL(player)) || map->map[y][x] == (RIVAL(player) - 32))
			{
				board->y_start_rival = y;
				board->x_start_rival = x;
			}
		}
	}
}