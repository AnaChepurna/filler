/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 14:44:06 by achepurn          #+#    #+#             */
/*   Updated: 2018/05/23 14:44:08 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <termcap.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <signal.h>

# define INIT		1
# define SET		2
# define RE_SET		3
# define GET_OLD	4
# define GET_NEW	5
# define STR 		1
# define CHR		2

struct termios	*manage_term(int mode);
int				get_map(int t);
void			start_signal_handling(void);

#endif
