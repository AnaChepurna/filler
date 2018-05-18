#include "../filler.h"

t_map	*new_map(void)
{
	t_map	*res;

	if ((res = (t_map *)malloc(sizeof(t_map))))
		res->map = NULL;
	return (res);
}

void	clear_map(t_map **map)
{
	if (*map && (*map)->map)
		ft_arrfree((&(*map)->map));
	if (*map)
		free(*map);
	*map = NULL;
}

t_board	*new_board(void)
{
	t_board *res;

	if ((res = (t_board *)malloc(sizeof(t_board))))
	{
		res->y_start_player = 0;
		res->x_start_player = 0;
		res->y_start_rival = 0;
		res->x_start_rival = 0;
	}
	return (res);
}

void	clear_board(t_board **board)
{
	if (board && *board)
		free(*board);
	*board = NULL;
}