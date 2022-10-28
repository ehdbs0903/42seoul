/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <daykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:44:29 by doykim            #+#    #+#             */
/*   Updated: 2022/10/28 18:45:35 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include "mlx/mlx.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3

# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2

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
	int			c_cnt;
	int			e_cnt;
	int			p_cnt;
	int			e_flag;
	char		*map;
	void		*mlx;
	void		*win;
	void		*floor;
	void		*wall;
	void		*collect;
	void		*exit;
	t_player	player;
}	t_game;

void	print_error(int n);
int		check_argument(int ac, char **av);
void	init_img(t_game *game);
void	set_map_img(t_game *game);
void	read_map(char *filename, t_game *game);
int		key_press(int keycode, t_game *game);
void	check_map(t_game *game);
void	put_img(t_game *game, void *img, int w, int h);

#endif
