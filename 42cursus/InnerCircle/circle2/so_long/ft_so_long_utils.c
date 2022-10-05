/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:23:03 by doykim            #+#    #+#             */
/*   Updated: 2022/10/05 21:27:30 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	init_img(t_game *game)
{
	int	width;
	int	height;

	game->grass = mlx_xpm_file_to_image(game->mlx, "./img/Grass.xpm", &width, &height);
	game->rock = mlx_xpm_file_to_image(game->mlx, "./img/Rock.xpm", &width, &height);
	game->blue_orb = mlx_xpm_file_to_image(game->mlx, "./images/Blue_orb.xpm", &width, &height);
	game->red_orb = mlx_xpm_file_to_image(game->mlx, "./images/Red_orb.xpm", &width, &height);
}

void	set_img(t_game *game)
{
	int		h;
	int		w;

	h = 0;
	while (h < game->height)
	{
		w = 0;
		while (w < game->width)
		{
			if (game->map[h * game->width + w] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->rock, w * 64, h * 64);
			else if (game->map[h * game->width + w] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->blue_orb, w * 64, h * 64);
			//else if (game->map[h * game->width + w] == 'P')
				//mlx_put_image_to_window(game->mlx, game->win, game->img_chara, w * 64, h * 64);
			else if (game->map[h * game->width + w] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->red_orb, w * 64, h * 64);
			else
				mlx_put_image_to_window(game->mlx, game->win, game->grass, w * 64, h * 64);
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
