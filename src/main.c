#include "../filler.h"

void	game(t_map *map, t_map *piece, char	player)
{
	t_board *board;

	board = new_board();
	get_start_positions(board, map, player);
	
	clear_boad(&board);
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