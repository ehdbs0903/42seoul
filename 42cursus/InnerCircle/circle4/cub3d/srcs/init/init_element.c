/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:39:01 by doykim            #+#    #+#             */
/*   Updated: 2023/02/08 20:31:46 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	xpm_file_to_image_texture(t_game *game)
{
	int	w;
	int	h;

	game->img_no.img = mlx_xpm_file_to_image(game->mlx, \
		game->no_path, &w, &h);
	game->img_so.img = mlx_xpm_file_to_image(game->mlx, \
		game->so_path, &w, &h);
	game->img_we.img = mlx_xpm_file_to_image(game->mlx, \
		game->we_path, &w, &h);
	game->img_ea.img = mlx_xpm_file_to_image(game->mlx, \
		game->ea_path, &w, &h);
	if (game->img_no.img == NULL || game->img_so.img == NULL \
		|| game->img_ea.img == NULL || game->img_we.img == NULL)
		error_exit(2);
}

static void	get_data_addr_texture(t_game *game)
{
	game->img_no.data = (int *)mlx_get_data_addr(game->img_no.img, \
		&(game->img_no.bpp), \
		&(game->img_no.line_len), &(game->img_no.endian));
	game->img_so.data = (int *)mlx_get_data_addr(game->img_so.img, \
		&(game->img_so.bpp), \
		&(game->img_so.line_len), &(game->img_so.endian));
	game->img_we.data = (int *)mlx_get_data_addr(game->img_we.img, \
		&(game->img_we.bpp), \
		&(game->img_we.line_len), &(game->img_we.endian));
	game->img_ea.data = (int *)mlx_get_data_addr(game->img_ea.img, \
		&(game->img_ea.bpp), \
		&(game->img_ea.line_len), &(game->img_ea.endian));
}

void	init_element(char **temp, t_game *game)
{
	static int	i = -1;
	int			len;

	len = ft_strlen_2d(temp);
	if (len <= 6)
		error_exit(2);
	while (++i < 6)
	{
		if (!ft_strncmp("NO ", temp[i], 3) || !ft_strncmp("SO ", temp[i], 3)
			|| !ft_strncmp("WE ", temp[i], 3) || !ft_strncmp("EA ", temp[i], 3))
			init_texture(game, temp[i]);
		else if (!ft_strncmp("F ", temp[i], 2) || !ft_strncmp("C ", temp[i], 2))
			init_rgb(game, temp[i]);
		else
			error_exit(2);
	}
	if (game->no_path == NULL || game->so_path == NULL \
		|| game->we_path == NULL || game->ea_path == NULL)
		error_exit(2);
	if (game->ceil < 0 || game->floor < 0)
		error_exit(2);
	read_map(temp, game);
	xpm_file_to_image_texture(game);
	get_data_addr_texture(game);
}

void	init_texture(t_game *game, char *line)
{
	char	*tmp;

	if (line[0] == 'N')
	{
		if (check_texture(line, &tmp))
			game->no_path = tmp;
	}
	else if (line[0] == 'S')
	{
		if (check_texture(line, &tmp))
			game->so_path = tmp;
	}
	else if (line[0] == 'W')
	{
		if (check_texture(line, &tmp))
			game->we_path = tmp;
	}
	else if (line[0] == 'E')
	{
		if (check_texture(line, &tmp))
			game->ea_path = tmp;
	}
}

int	check_texture(char *line, char **tmp)
{
	int	fd;

	line += 3;
	while (ft_isspace(*line))
		line++;
	fd = open(line, O_RDONLY);
	if (fd == -1)
		error_exit(2);
	close(fd);
	*tmp = ft_strdup(line);
	return (1);
}
