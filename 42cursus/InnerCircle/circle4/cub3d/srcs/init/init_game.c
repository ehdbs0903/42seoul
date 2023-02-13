/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:48:22 by doykim            #+#    #+#             */
/*   Updated: 2023/02/08 12:42:28 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(int ac, char *av[], t_game *game, t_img *img)
{
	ft_memset(game, 0, sizeof(t_game));
	ft_memset(img, 0, sizeof(t_img));
	game->image = img;
	game->ceil = -1;
	game->floor = -1;
	game->movespeed = 0.101;
	game->rotspeed = 0.0505;
	game->mlx = mlx_init();
	check_file(ac, av, game);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3d");
}
