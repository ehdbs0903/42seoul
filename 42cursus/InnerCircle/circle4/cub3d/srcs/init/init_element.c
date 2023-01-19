/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:39:01 by doykim            #+#    #+#             */
/*   Updated: 2023/01/19 20:10:57 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_element(char *buff, t_game *game)
{
	char	**temp;
	int		len;
	int		i;

	temp = ft_split(buff, '\n');
	len = ft_strlen_2d(temp);
	if (len <= 6)
		error_exit(2);
	i = 0;
	while (i < 6)
	{
		if (!ft_strncmp("NO ", temp[i], 3) || !ft_strncmp("SO ", temp[i], 3)
			|| !ft_strncmp("WE ", temp[i], 3) || !ft_strncmp("EA ", temp[i], 3))
			init_texture(game, temp[i]);
		else if (!ft_strncmp("F ", temp[i], 2) || !ft_strncmp("C ", temp[i], 2))
			init_rgb(game, temp[i]);
		else
			error_exit(2);
		i++;
	}
	read_map(temp, game);
	free_2d_array(temp);
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
		game->floor.r = ft_atoi(temp[0]);
		game->floor.g = ft_atoi(temp[1]);
		game->floor.b = ft_atoi(temp[2]);
	}
	else if (c == 'C')
	{
		game->ceil.r = ft_atoi(temp[0]);
		game->ceil.g = ft_atoi(temp[0]);
		game->ceil.b = ft_atoi(temp[0]);
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
