/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rgb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:34:16 by doykim            #+#    #+#             */
/*   Updated: 2023/02/08 20:40:17 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_rgb(t_game *game, char *line)
{
	char	**temp;
	char	c;

	c = line[0];
	line += 2;
	while (ft_isspace(*line))
		line++;
	temp = ft_split(line, ',');
	check_rgb_num(temp);
	if (c == 'F')
	{
		game->floor = (ft_atoi(temp[0]) << 16 \
				| ft_atoi(temp[1]) << 8 | ft_atoi(temp[2]));
	}
	else if (c == 'C')
	{
		game->ceil = (ft_atoi(temp[0]) << 16 \
				| ft_atoi(temp[1]) << 8 | ft_atoi(temp[2]));
	}
	free_2d_array(temp);
}

void	check_rgb_num(char **temp)
{
	int	i;
	int	j;
	int	len;
	int	num;

	if (ft_strlen_2d(temp) != 3)
		error_exit(2);
	i = -1;
	while (++i < 3)
	{
		len = ft_strlen(temp[i]);
		j = 0;
		while (j < len)
		{
			if (!ft_isdigit(temp[i][j++]))
				error_exit(2);
		}
	}
	i = 0;
	while (i < 3)
	{
		num = ft_atoi(temp[i++]);
		if (num < 0 || num > 255)
			error_exit(2);
	}
}

void	*make_rgb_img(t_game *game, int rgb)
{
	t_img	image;
	int		i;
	int		j;

	image.img = mlx_new_image(game->mlx, 1920, 540);
	if (image.img == NULL)
		exit(1);
	image.data = (int *)mlx_get_data_addr(image.img, &image.bpp, \
			&image.line_len, &image.endian);
	i = 0;
	while (i < 540)
	{
		j = 0;
		while (j < 1920)
		{
			image.data[i * image.line_len / 4 + j] = rgb;
			j++;
		}
		i++;
	}
	return (image.img);
}
