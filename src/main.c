#include "../filler.h"

void	input_error(void)
{
	ft_putstr_fd("Wrong input!\n", 2);
	exit(0);
}

void	game(t_map *map, t_map *piece, char	player)
{
	static t_board *board = NULL;

	if (!board)
		board = new_board();
	ft_putendl_fd("game", 2);
	get_start_positions(board, map, player);
	if (!algorythm1(map, piece, board, player))
		area_4(map, piece, board, player);
	ft_putstr_fd("to print ", 2);
	ft_putnbr_fd(board->y_place, 2);
	ft_putchar_fd(' ', 2);
	ft_putnbr_fd(board->x_place, 2);
	ft_putchar_fd('\n', 2);
		ft_putnbr(board->y_place);
		ft_putchar(' ');
		ft_putnbr(board->x_place);
		ft_putchar('\n');
		board->y_start_player = board->y_place;
		board->x_start_player = board->x_place;
	//clear_board(&board);
}

int 	main(int c, char **v)
{
	t_map 	*map;
	t_map 	*piece;
	char	player;

	(void)c;
	player = get_player(v[0]);
	while (42)
	{
		map = get_map();
		piece = get_map();
		game(map, piece, player);
		clear_map(&map);
		clear_map(&piece);
	}
	return (0);
}