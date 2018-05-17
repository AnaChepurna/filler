#ifndef FILLER_H
#define FILLER_H

# include "libft/libft.h"
# include <fcntl.h>

# define MAP	4
# define PIECE	0

typedef struct		s_map
{
	int 			x;
	int 			y;
	char			**map;
}					t_map;

// typedef struct 		s_piece
// {
// 	int				x;
// 	int				y;
// 	char			**piece;
// }					t_piece;

/*
**parse.c
*/
t_map				*get_map(void);
void				clear_map(t_map **map);

/*
**error.c
*/
void				input_error(void);

#endif