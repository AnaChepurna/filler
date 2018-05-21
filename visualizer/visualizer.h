#ifndef VISUALIZER_H
#define VISUALIZER_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <termcap.h>
# include <termios.h>

# define INIT		1
# define SET		2
# define RE_SET		3
# define GET_OLD	4
# define GET_NEW	5
# define STR 		1
# define CHR		2

struct termios	*manage_term(int mode);
int				get_map(void);

#endif