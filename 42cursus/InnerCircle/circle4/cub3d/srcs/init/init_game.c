/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:48:22 by doykim            #+#    #+#             */
/*   Updated: 2023/01/19 21:02:32 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(int ac, char *av[], t_game *game)
{
	game->p_flag = 0;
	game->map = NULL;
	game->no_path = NULL;
	game->so_path = NULL;
	game->we_path = NULL;
	game->ea_path = NULL;
	game->floor.r = 0;
	game->floor.g = 0;
	game->floor.b = 0;
	game->ceil.r = 0;
	game->ceil.g = 0;
	game->ceil.b = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->player.dir = 0;
	check_file(ac, av, game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 1920, 1080, "cub3d");
}
