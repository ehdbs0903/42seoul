/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:23:03 by doykim            #+#    #+#             */
/*   Updated: 2022/10/28 18:45:32 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	init_img(t_game *game)
{
	int	width;
	int	height;

	game->floor = mlx_xpm_file_to_image(game->mlx, "./img/floor.xpm", &width,
			&height);
	game->wall = mlx_xpm_file_to_image(game->mlx, "./img/wall.xpm", &width,
			&height);
	game->collect = mlx_xpm_file_to_image(game->mlx, "./img/collect.xpm",
			&width, &height);
	game->exit = mlx_xpm_file_to_image(game->mlx, "./img/exit.xpm", &width,
			&height);
	//game->o_exit = mlx_xpm_file_to_image(game->mlx, "./img/o_exit.xpm", &width,
	//		&height);
	game->player.front = mlx_xpm_file_to_image(game->mlx, "./img/front.xpm",
			&width, &height);
	game->player.back = mlx_xpm_file_to_image(game->mlx, "./img/back.xpm",
			&width, &height);
	game->player.left = mlx_xpm_file_to_image(game->mlx, "./img/left.xpm",
			&width, &height);
	game->player.right = mlx_xpm_file_to_image(game->mlx, "./img/right.xpm",
			&width, &height);
}

void	set_map_img(t_game *game)
{
	int		h;
	int		w;

	h = -1;
	while (++h < game->height)
	{
		w = -1;
		while (++w < game->width)
		{
			put_img(game, game->floor, w, h);
			if (game->map[h * game->width + w] == '1')
				put_img(game, game->wall, w, h);
			else if (game->map[h * game->width + w] == 'C')
				put_img(game, game->collect, w, h);
			else if (game->map[h * game->width + w] == 'P')
				put_img(game, game->player.front, w, h);
			else if (game->map[h * game->width + w] == 'E')
				put_img(game, game->exit, w, h);
			else if (game->map[h * game->width + w] == '0')
				continue ;
			else
				print_error(1);
		}
	}
}

void	read_map(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_error(1);
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
	check_map(game);
	ft_printf("%s\n", game->map);
}

void	check_map(t_game *game)
{
	int	h;
	int	w;

	h = -1;
	while (++h < game->height)
	{
		w = -1;
		while (++w < game->width)
		{	
			if ((h == 0 || h == game->height - 1) && game->map[h * game->width + w] != '1')
				print_error(1);
			if ((w == 0 || w == game->width - 1) && game->map[h * game->width + w] != '1')
				print_error(1);
			if (game->map[h * game -> width + w] == 'P')
			{
				game->p_cnt++;
				game->player.x = w;
				game->player.y = h;
			}
			else if (game->map[h * game -> width + w] == 'C')
				game->c_cnt++;
			else if (game->map[h * game -> width + w] == 'E')
				game->e_cnt++;
		}
	}
	if (game->c_cnt != 1 || !game->p_cnt || !game->e_cnt)
		print_error(1);
	game->c_cnt = c;
}
