/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:55:45 by doykim            #+#    #+#             */
/*   Updated: 2023/01/19 21:13:53 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
	{
		move(game, 0, 1);
	}
	else if (keycode == KEY_S)
	{
		move(game, 0, -1);
	}
	else if (keycode == KEY_A)
	{
		move(game, 1, 0);
	}
	else if (keycode == KEY_D)
	{
		move(game, -1, 0);
	}
	else if (keycode == KEY_ESC)
		exit(2);
	return (0);
}

void	move(t_game *game, int dx, int dy)
{
	if (game->map[game->player.y + dy][game->player.x + dx] != '1')
	{
//		game->map[game->player.y + dy][game->player.x + dx] = '0';
		game->player.x += dx;
		game->player.y += dy;
	}
	printf("x y : %d %d\n", game->player.x, game->player.y);
}

int	x_exit(int n)
{
	n = 0;
	exit(n);
	return (0);
}
