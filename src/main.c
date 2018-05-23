/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 14:28:32 by achepurn          #+#    #+#             */
/*   Updated: 2018/05/23 14:28:34 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void	game(t_map *map, t_map *piece, char	player)
{
	static t_board *board = NULL;
	int status;

	if (!board)
		board = new_board();
	board->player = player;
	get_start_positions(board, map);
	if (map->x * map->y > 400)
	{
		status = algorythm2(map, piece, board);
		if (!status)
			status = algorythm1(map, piece, board);
	}
	else
		status = algorythm1(map, piece, board);
	if (!status)
		area_4(map, piece, board);
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
