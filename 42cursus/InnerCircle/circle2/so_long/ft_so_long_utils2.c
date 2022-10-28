/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 01:36:58 by doykim            #+#    #+#             */
/*   Updated: 2022/10/28 18:45:33 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	move_w(t_game *game)
{
	int w;
	int h;

	h = game->player.y;
	w = game->player.x;
	if (game->map[(h - 1) * game->width + w] != '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->floor,
				game->player.x * 50, game->player.y * 50);
		game->player.y--;
		if (game->map[(h - 1) * game->width + w] == 'C')
		{
			game->c_cnt -= 1;
			if (!game->c_cnt)
				game->e_flag = 1;
		}
		if (game->map[(h - 1) * game->width + w] == 'E')
			if (game->e_flag)
			{
				ft_printf("Sucess");
				exit(0);
			}
		mlx_put_image_to_window(game->mlx, game->win, game->floor,
				game->player.x * 50, game->player.y * 50);
		mlx_put_image_to_window(game->mlx, game->win, game->player.back,
				game->player.x * 50, game->player.y * 50);
	}
}

void	move_s(t_game *game)
{
	int w;
	int h;

	h = game->player.y;
	w = game->player.x;
	if (game->map[(h + 1) * game->width + w] != '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->floor, game->player.x * 50, game->player.y * 50);
		game->player.y++;
		if (game->map[(h + 1) * game->width + w] == 'C')
		{
			game->c_cnt -= 1;
			if (!game->c_cnt)
				game->e_flag = 1;
		}
		if (game->map[(h + 1) * game->width + w] == 'E')
			if (game->e_flag)
			{
				ft_printf("Sucess");
				exit(0);
			}
		mlx_put_image_to_window(game->mlx, game->win, game->floor, game->player.x * 50, game->player.y * 50);
		mlx_put_image_to_window(game->mlx, game->win, game->player.front, game->player.x * 50, game->player.y * 50);
	}
}

void	move_a(t_game *game)
{
	int w;
	int h;

	h = game->player.y;
	w = game->player.x;
	if (game->map[h * game->width + w - 1] != '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->floor, game->player.x * 50, game->player.y * 50);
		game->player.x--;
		if (game->map[h * game->width + w - 1] == 'C')
		{
			game->c_cnt -= 1;
			if (!game->c_cnt)
				game->e_flag = 1;
		}
		if (game->map[h * game->width + w - 1] == 'E')
			if (game->e_flag)
			{
				ft_printf("Sucess");
				exit(0);
			}
		mlx_put_image_to_window(game->mlx, game->win, game->floor, game->player.x * 50, game->player.y * 50);
		mlx_put_image_to_window(game->mlx, game->win, game->player.left, game->player.x * 50, game->player.y * 50);
	}
}

void	move_d(t_game *game)
{
	int w;
	int h;

	h = game->player.y;
	w = game->player.x;
	if (game->map[h * game->width + w + 1] != '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->floor, game->player.x * 50, game->player.y * 50);
		game->player.x++;
		if (game->map[h * game->width + w + 1] == 'C')
		{
			game->c_cnt -= 1;
			if (!game->c_cnt)
				game->e_flag = 1;
		}
		if (game->map[h * game->width + w + 1] == 'E')
			if (game->e_flag)
			{
				ft_printf("Sucess");
				exit(0);
			}
		mlx_put_image_to_window(game->mlx, game->win, game->floor, game->player.x * 50, game->player.y * 50);
		mlx_put_image_to_window(game->mlx, game->win, game->player.right, game->player.x * 50, game->player.y * 50);
	}
}

int	key_press(int keycode, t_game *game)
{
	ft_printf("%d\n", keycode);
	if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A || keycode == KEY_D)
	{
		if (keycode == KEY_W)
			move_w(game);
		else if (keycode == KEY_S)
			move_s(game);
		else if (keycode == KEY_A)
			move_a(game);
		else if (keycode == KEY_D)
			move_d(game);
	}
	else if (keycode == KEY_ESC)
		exit(0);
	ft_printf("x: %d, y: %d\n", game->player.x, game->player.y);
	return (0);
}
