#ifndef FILLER_H
#define FILLER_H

# include "libft/libft.h"
# include <fcntl.h>

# define MAP	4
# define PIECE	0
# define P1		'o'
# define P2		'x'

typedef struct		s_map
{
	int 			x;
	int 			y;
	char			**map;
}					t_map;

typedef struct 		s_board
{
	int				y_start_player;
	int				x_start_player;
	int				y_start_rival;
	int				x_start_rival;
	int				y_place;
	int				x_place;	
}					t_board;

/*
**memory,c
*/
void				clear_map(t_map **map);
t_map				*new_map(void);
t_board				*new_board(void);
void				clear_board(t_board **board);

/*
**parse.c
*/
t_map				*get_map(void);
char				get_player(char *name);

/*
**analyze.c
*/
void				get_start_positions(t_board *board, t_map *map,
	char player);

/*
**error.c
*/
void				input_error(void);

#endif