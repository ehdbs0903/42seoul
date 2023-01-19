/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:52:43 by doykim            #+#    #+#             */
/*   Updated: 2023/01/19 21:13:50 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	read_map(char **temp, t_game *game)
{
	int	i;
	int	j;
	int	len;

	i = 6;
	j = 0;
	len = ft_strlen_2d(temp) - 6;
	game->map = (char **)malloc(sizeof(char *) * (len + 1));
	while (temp[i])
	{
		game->map[j] = ft_strdup(temp[i++]);
		j++;
	}
	game->map[j] = NULL;
	check_map(game->map, game);
}

void	check_map(char **temp, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (temp[++i])
	{
		j = -1;
		while (temp[i][++j])
		{
			if (temp[i][j] == '0')
			{
				if (i == 0 || j == 0)
					error_exit(3);
				else if (!temp[i + 1][j] || !temp[i][j + 1])
					error_exit(3);
				else if (temp[i][j - 1] == ' ' || temp[i][j + 1] == ' ')
					error_exit(3);
				else if (temp[i + 1][j] == ' ' || temp[i - 1][j] == ' ')
					error_exit(3);
			}
			else if (temp[i][j] != ' ' && temp[i][j] != '1')
				init_player(temp[i][j], j, i, game);
		}
	}
}

void	init_player(char c, int x, int y, t_game *game)
{
	if (game->p_flag)
		error_exit(3);
	else
	{
		game->p_flag = 1;
		if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		{
			game->player.dir = c;
			game->player.x = x;
			game->player.y = y;
		}
		else
			error_exit(3);
	}
}
