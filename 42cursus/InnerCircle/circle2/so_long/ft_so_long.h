/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <daykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:44:29 by doykim            #+#    #+#             */
/*   Updated: 2022/10/28 01:37:33 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include "mlx/mlx.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>

typedef struct s_player
{
	int		x;
	int		y;
	void	*front;
	void	*back;
	void	*left;
	void	*right;
}	t_player;

typedef struct s_game
{
	int			width;
	int			height;
	char		*map;
	void		*mlx;
	void		*win;
	void		*floor;
	void		*wall;
	void		*collect;
	void		*exit;
	void		*o_exit;
	t_player	player;
}	t_game;

void	print_error();
int		check_argument(int ac, char **av);
void	init_img(t_game *game);
void	set_map_img(t_game *game);
void	read_map(char *filename, t_game *game);

#endif
