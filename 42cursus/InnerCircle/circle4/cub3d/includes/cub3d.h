/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:32:29 by doykim            #+#    #+#             */
/*   Updated: 2023/02/02 20:17:10 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define KEY_ESC	53
# define KEY_W		13
# define KEY_S		1
# define KEY_A		0
# define KEY_D		2
# define KEY_LEFT	123
# define KEY_RIGHT	124

# define WIDTH		1920
# define HEIGHT		1080

typedef struct	s_img
{
	void	*img;
	int		*data;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
}	t_player;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			p_flag;
	double		plane_x;
	double		plane_y;
	char		**map;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	void		*floor;
	void		*ceil;
	float		movespeed;
	float		rotspeed;
	t_player	player;
	t_img	img;
	t_img	img_no;
	t_img	img_so;
	t_img	img_we;
	t_img	img_ea;
}	t_game;

//init
void	init_game(int ac, char *av[], t_game *game);

void	check_file(int ac, char **av, t_game *game);
void	check_argument(int ac, char **av);

void	init_element(char *buff, t_game *game);
void	init_texture(t_game *game, char *line);
int		check_texture(char *line, char **tmp);

void	init_rgb(t_game *game, char *line);
void	check_rgb_num(char **temp);
void	*make_rgb_img(t_game *game, int rgb);

void	read_map(char **temp, t_game *game);
void	check_map(char **temp, t_game *game);
void	init_player(char c, int x, int y, t_game *game);
void	init_dir(char dir, t_game *game);

//loop
int		main_loop(t_game *game);

//key
int		key_press(int key, t_game *game);
//void	move(t_game *game, int dx, int dy);
int		x_exit(int n);

//utils
void	error_exit(int n);
void	free_2d_array(char **str);
void	print_2d(char **arr);

int		raycasting(t_game *game);
#endif
