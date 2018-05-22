#ifndef FILLER_H
#define FILLER_H

# include "libft/libft.h"
# include <fcntl.h>

# define MAP		4
# define PIECE		0
# define P1			'o'
# define P2			'x'
# define RIVAL(x)	((x) == P1 ? P2 : P1)

typedef struct		s_map
{
	int 			x;
	int 			y;
	char			**map;
}					t_map;

typedef struct 		s_board
{
	char			player;	
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
void				get_start_positions(t_board *board, t_map *map);
int					check_place(t_map *map, t_map *piece, t_board *board);
int					check_rival(t_map *map, char player);

/*
**algorythm1.c
*/
int					algorythm1(t_map *map, t_map *piece, t_board *board);
int					area_1(t_map *map, t_map *piece, t_board *board);
int					area_4(t_map *map, t_map *piece, t_board *board);
int					area_3(t_map *map, t_map *piece, t_board *board);
int					area_2(t_map *map, t_map *piece, t_board *board);


int				algorythm2(t_map *map, t_map *piece, t_board *board);
int		check_place_rival(t_map * map, t_map *piece, t_board *board);
/*
**main.c
*/
void				input_error(void);

#endif