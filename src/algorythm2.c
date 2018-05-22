#include "../filler.h"

int				area2_1(t_map *map, t_map *piece, t_board *board)
{
	board->y_place = map->y;
	while (board->y_place > 0)
	{
		board->x_place = map->x;
		while (board->x_place > 0)
		{
			if (check_place(map, piece, board) && check_place_rival(map, piece, board))
				return (1);
			board->x_place--;
		}
		board->y_place--;
	}
	return (0);
}

int		area2_2(t_map *map, t_map *piece, t_board *board)
{
	board->y_place = map->y;
	while (board->y_place > 0)
	{
		board->x_place = -1;
		while (++(board->x_place) < map->x)
		{
			if (check_place(map, piece, board) && check_place_rival(map, piece, board))
				return (1);
		}
		board->y_place--;
	}
	return (0);
}

int				area2_3(t_map *map, t_map *piece, t_board *board)
{
	board->y_place = -1;
	while (++(board->y_place) < map->y)
	{
		board->x_place = map->x;
		while (board->x_place > 0)
		{
			if (check_place(map, piece, board) && check_place_rival(map, piece, board))
				return (1);
			board->x_place--;
		}
	}
	return (0);
}

int		area2_4(t_map *map, t_map *piece, t_board *board)
{
	board->y_place = -1;
	while (++(board->y_place) < map->y)
	{
		board->x_place = -1;
		while (++(board->x_place) < map->x)
		{
			if (check_place(map, piece, board) && check_place_rival(map, piece, board))
				return (1);
		}
	}
	return (0);
}

int				algorythm2(t_map *map, t_map *piece, t_board *board)
{
	if (check_rival(map, board->player))
	{
		if (board->y_start_player < map->y / 2)
		{
			if (board->x_start_player < map->x / 3)
				return (area2_3(map, piece, board));
			if (board->x_start_player < map->x * 3 / 4)
				return (area2_1(map, piece, board));
			else
				return (area2_2(map, piece, board));
		}
		else
		{
			if (board->x_start_player < map->x * 3 / 4)
			return (area2_4(map, piece, board));
			else
				return (area2_4(map, piece, board));
		}
	}
	else
	{
		if (board->y_start_player < board->y_start_rival)
			return (area_1(map, piece, board));
		else
			return (area_4(map, piece, board));
	}
}