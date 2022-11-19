/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <daykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:44:29 by doykim            #+#    #+#             */
/*   Updated: 2022/11/01 17:09:33 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include "mlx/mlx.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>

# define KEY_ESC	53

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
	int			img_w;
	int			img_h;
	int			m_cnt;
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
	void		*monster;
	t_player	player;
}	t_game;

void	exit_game(int n);
void	init_img(t_game *game);
void	set_map_img(t_game *game);
void	read_map(char *filename, t_game *game);
int		key_press(int keycode, t_game *game);
void	check_map(t_game *game);
void	put_img(t_game *game, void *img, int w, int h);
void	draw_text(t_game *game);

#endif
