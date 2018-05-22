#include "../filler.h"

int		check_place(t_map *map, t_map *piece, t_board *board)
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
				if (map->map[y + board->y_place][x + board->x_place] == board->player - 32
					|| map->map[y + board->y_place][x + board->x_place] == board->player)
					n++;
				if (map->map[y + board->y_place][x + board->x_place] == (RIVAL(board->player)) - 32
					|| map->map[y + board->y_place][x + board->x_place] == (RIVAL(board->player)))
					return (board->player == P2 ? 1 : 0);
			}
		}
	}
	return (n == 1 ? 1 : 0);
}

static int		is_near_rival(int x, int y, t_map *map, char player)
{
	int x1;
	int y1;
	char rival;

	rival = RIVAL(player);
	y1 = y - 3;
	while (y1 > -1 && y1 < map->y && y1 <= y + 3)
	{
		x1 = x - 3;
		while (x1 > -1 && x1 < map->x && x1 <= x - 3)
		{
			if (map->map[y1][x1] == rival || map->map[y1][x1] == rival - 32)
				return (1);
			x1++;
		}
		y1++;
	}
	return (0);
}

int		check_place_rival(t_map * map, t_map *piece, t_board *board)
{
	int x;
	int y;

	y = -1;
	while(++y < piece->y)
	{
		x = -1;
		while (++x < piece->x)
		{
			if (piece->map[y][x] == '*' && is_near_rival(x + board->x_place, y + board->y_place, map, board->player))
				return (1);
		}
	}
	return (0);
}

int		check_rival(t_map *map, char player)
{
	int		x;
	int		y;

	y = 3;
	while (y < map->y - 3)
	{
		x = 3;
		while (x < map->x - 3)
		{
			if ((map->map[y][x] == player || map->map[y][x] == player - 32)
				&& is_near_rival(x, y, map, player))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	get_start_positions(t_board *board, t_map *map)
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
			if (map->map[y][x] == board->player || map->map[y][x] == board->player - 32)
			{
				board->y_start_player = y;
				board->x_start_player = x;
			}
			if (map->map[y][x] == (RIVAL(board->player)) ||
				map->map[y][x] == (RIVAL(board->player) - 32))
			{
				board->y_start_rival = y;
				board->x_start_rival = x;
			}
		}
	}
}