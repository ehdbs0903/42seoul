/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:23:03 by doykim            #+#    #+#             */
/*   Updated: 2022/10/28 01:37:31 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	init_img(t_game *game)
{
	int	width;
	int	height;

	game->floor = mlx_xpm_file_to_image(game->mlx, "./img/floor.xpm", &width, &height);
	game->wall = mlx_xpm_file_to_image(game->mlx, "./img/wall.xpm", &width, &height);
	game->collect = mlx_xpm_file_to_image(game->mlx, "./img/collect.xpm", &width, &height);
	game->exit = mlx_xpm_file_to_image(game->mlx, "./img/exit.xpm", &width, &height); 
	game->o_exit = mlx_xpm_file_to_image(game->mlx, "./img/o_exit.xpm", &width, &height);
	game->player.front = mlx_xpm_file_to_image(game->mlx, "./img/front.xpm", &width, &height);
	game->player.back = mlx_xpm_file_to_image(game->mlx, "./img/back.xpm", &width, &height);
	game->player.left = mlx_xpm_file_to_image(game->mlx, "./img/left.xpm", &width, &height);
	game->player.right = mlx_xpm_file_to_image(game->mlx, "./img/right.xpm", &width, &height);

}

void	set_map_img(t_game *game)
{
	int		h;
	int		w;

	h = 0;
	while (h < game->height)
	{
		w = 0;
		while (w < game->width)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->floor, w * 50, h * 50);
			if (game->map[h * game->width + w] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall, w * 50, h * 50);
			else if (game->map[h * game->width + w] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->collect, w * 50, h * 50);
			else if (game->map[h * game->width + w] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->player.front, w * 50, h * 50);
			else if (game->map[h * game->width + w] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit, w * 50, h * 50);
			w++;
		}
		h++;
	}
}

void	read_map(char *filename, t_game *game)
{
	int  fd;
	char *line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_error();
	line = get_next_line(fd);
	game->height = 0;
	game->width = ft_strlen(line) - 1;
	game->map = line;
	game->map[ft_strlen(game->map) - 1] = 0;
	while (line)
	{
		game->height++;
		line = get_next_line(fd);
		if (line)
		{
			game->map = ft_strjoin(game->map, line);
			game->map[ft_strlen(game->map) - 1] = 0;
		}
	}
	close(fd);
	ft_printf("%s\n", game->map);
}
