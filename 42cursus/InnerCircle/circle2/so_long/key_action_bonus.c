/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 01:36:58 by doykim            #+#    #+#             */
/*   Updated: 2022/11/01 17:08:24 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static	void	move_bonus(t_game *game, t_player player, int dy, int dx)
{
	if (game->map[(player.y + dy) * game->width + player.x + dx] != '1')
	{	
		if (game->map[(player.y + dy) * game->width + player.x + dx] == 'M')
			exit_game(-1);
		if (game->map[(player.y + dy) * game->width + player.x + dx] == 'C')
		{
			game->c_cnt -= 1;
			if (!game->c_cnt)
				game->e_flag = 1;
			game->map[(player.y + dy) * game->width + player.x + dx] = '0';
		}
		if (game->map[(player.y + dy) * game->width + player.x + dx] == 'E')
		{
			if (game->e_flag)
				exit_game(0);
			else
				return ;
		}
		put_img(game, game->floor, player.x, player.y);
		put_img(game, game->floor, player.x + dx, player.y + dy);
		put_img(game, game->player.back, player.x + dx, player.y + dy);
		game->player.x += dx;
		game->player.y += dy;
		game->m_cnt += 1;
	}
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == 13)
	{
		move_bonus(game, game->player, -1, 0);
		put_img(game, game->player.back, game->player.x, game->player.y);
	}
	else if (keycode == 1)
	{
		move_bonus(game, game->player, 1, 0);
		put_img(game, game->player.front, game->player.x, game->player.y);
	}
	else if (keycode == 0)
	{
		move_bonus(game, game->player, 0, -1);
		put_img(game, game->player.left, game->player.x, game->player.y);
	}
	else if (keycode == 2)
	{
		move_bonus(game, game->player, 0, 1);
		put_img(game, game->player.right, game->player.x, game->player.y);
	}
	else if (keycode == KEY_ESC)
		exit(2);
	draw_text(game);
	return (0);
}
