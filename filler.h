#ifndef FILLER_H
#define FILLER_H

# include "libft/libft.h"
# include <fcntl.h>

typedef struct		s_map
{
	int 			x;
	int 			y;
	char			**map;
}					t_map;

/*
**map.c
*/
t_map				*get_map(void);
void				clear_map(t_map **map);

/*
**error.c
*/
void				map_error(void);

#endif