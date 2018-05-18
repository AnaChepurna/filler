#include "../filler.h"

static int		area_1(t_map *map, t_map *piece, t_board *board, char player)
{
	ft_putendl_fd("2", 2);
	board->y_place = map->y;
	while (board->y_place > 0)
	{
		board->x_place = map->x;
		while (board->x_place > 0)
		{
			if (check_place(map, piece, board, player))
				return (1);
			board->x_place--;
		}
		board->y_place--;
	}
	return (0);
}

static int		area_2(t_map *map, t_map *piece, t_board *board, char player)
{
	ft_putendl_fd("2", 2);
	board->y_place = map->y;
	while (board->y_place > 0)
	{
		board->x_place = -1;
		while (++(board->x_place) < map->x)
		{
			if (check_place(map, piece, board, player))
				return (1);
		}
		board->y_place--;
	}
	return (0);
}

static int		area_3(t_map *map, t_map *piece, t_board *board, char player)
{
	ft_putendl_fd("3", 2);
	board->y_place = -1;
	while (++(board->y_place) < map->y)
	{
		board->x_place = map->x;
		while (board->x_place > 0)
		{
			if (check_place(map, piece, board, player))
				return (1);
			board->x_place--;
		}
	}
	return (0);
}

static int		area_4(t_map *map, t_map *piece, t_board *board, char player)
{
	ft_putendl_fd("4", 2);
	board->y_place = -1;
	while (++(board->y_place) < map->y)
	{
		board->x_place = -1;
		while (++(board->x_place) < map->x)
		{
			if (check_place(map, piece, board, player))
				return (1);
		}
	}
	return (0);
}

int				algorythm(t_map *map, t_map *piece, t_board *board, char player)
{
	ft_putendl_fd("algo", 2);
	if (board->y_start_player < map->y / 2)
	{
		if (board->x_start_player < map->x / 2)
			return (area_1(map, piece, board, player));
		else
			return (area_2(map, piece, board, player));
	}
	else
	{
		if (board->x_start_player < map->x / 2)
			return (area_3(map, piece, board, player));
		else
			return (area_4(map, piece, board, player));
	}
}