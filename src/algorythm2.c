#include "../filler.h"

static int		count_rival(t_map *map, t_map *piece, char player, int x, int y)
{
	int	x1;
	int y1;
	int n;
	int count;

	y1 = -1;
	count = 0;
	while (++y1 < piece->y)
	{
		x1 = -1;
		while (++x1 < piece->x)
		{
			n = 0;
			while (++o < 4)
		}
	}
}

static int		ring_rival(t_map *map, t_map *piece, t_board *board, char player)
{
	int 	x;
	int		y;
	int		count;
	int		tmp;

	count = -1;
	y = map->y;
	while (--y >= 0)
	{
		x = map->x;
		while (--x >= 0)
			if (chech_place(map, piece, board, player))
			{
				tmp = count_rival(map, piece, player, x, y);
				if (tmp > count)
				{
					count = tmp;
					board->y_place = y;
					board->x_place = x;
				}
			}
	}
	return (count > -1 ? 1 : 0);
}

int				algorythm2(t_map *map, t_map *piece, t_board *board, char player)
{
	if (chech_rival(map, player))
		return (ring_rival(map, piece, board, player));
	else
	{
		if (board->y_start_player < board->y_start_rival)
			return (area_1(map, piece, board, player));
		else
			return (area_4(map, piece, board, player));
	}
}