/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:32:29 by doykim            #+#    #+#             */
/*   Updated: 2023/01/19 19:54:03 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "../libs/libft/libft.h"

# define KEY_ESC	53
# define KEY_W		13
# define KEY_S		1
# define KEY_A		0
# define KEY_D		2

typedef struct s_player
{
	int		x;
	int		y;
	char	dir;
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
	char		**map;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	t_rgb		floor;
	t_rgb		ceil;
	t_player	player;
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

void	read_map(char **temp, t_game *game);
void	check_map(char **temp, t_game *game);
void	init_player(char c, int x, int y, t_game *game);

//key
int		key_press(int keycode, t_game *game);
void	move(t_game *game, int dx, int dy);
int		x_exit(int n);

//utils
void	error_exit(int n);
void	free_2d_array(char **str);
void	print_2d(char **arr);

#endif
