#include "../filler.h"

int				area_1(t_map *map, t_map *piece, t_board *board)
{
	board->y_place = map->y;
	while (board->y_place >= 0)
	{
		board->x_place = map->x;
		while (board->x_place >= 0)
		{
			if (check_place(map, piece, board))
				return (1);
			board->x_place--;
		}
		board->y_place--;
	}
	return (0);
}

int				area_2(t_map *map, t_map *piece, t_board *board)
{
	board->y_place = map->y;
	while (board->y_place >= 0)
	{
		board->x_place = -1;
		while (++(board->x_place) < map->x)
		{
			if (check_place(map, piece, board))
				return (1);
		}
		board->y_place--;
	}
	return (0);
}

int				area_3(t_map *map, t_map *piece, t_board *board)
{
	board->y_place = -1;
	while (++(board->y_place) < map->y)
	{
		board->x_place = map->x;
		while (board->x_place >= 0)
		{
			if (check_place(map, piece, board))
				return (1);
			board->x_place--;
		}
	}
	return (0);
}

int		area_4(t_map *map, t_map *piece, t_board *board)
{
	board->y_place = -1;
	while (++(board->y_place) < map->y)
	{
		board->x_place = -1;
		while (++(board->x_place) < map->x)
		{
			if (check_place(map, piece, board))
				return (1);
		}
	}
	return (0);
}

int				algorythm1(t_map *map, t_map *piece, t_board *board)
{
	if (board->y_start_player < map->y / 2)
	{
		if (board->x_start_player < map->x / 2)
			return (area_1(map, piece, board));
		else
			return (area_2(map, piece, board));
	}
	else
	{
		if (board->x_start_player < map->x / 2)
			return (area_3(map, piece, board));
		else
			return (area_4(map, piece, board));
	}
}