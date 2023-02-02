/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:40:49 by doykim            #+#    #+#             */
/*   Updated: 2023/02/02 20:17:09 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_leak(void)
{
	system("leaks cub3d");
}

int	main(int ac, char *av[])
{
	t_game	game;

//	atexit(check_leak);
	init_game(ac, av, &game);

	printf("\n\n"); ///구조체 변수 체크

	print_2d(game.map);

	printf("\nno_path : %s\n", game.no_path);
	printf("so_path : %s\n", game.so_path);
	printf("we_path : %s\n", game.we_path);
	printf("ea_path : %s\n", game.so_path);

	printf("\nplayer pos : %f, %f\n", game.player.x, game.player.y);
	printf("player dir : %f, %f\n", game.player.dir_x, game.player.dir_y);

	printf("\n\n-------------------------------\n\n\n");

	mlx_hook(game.win, 2, 0, key_press, &game);
//	mlx_hook(game.win, 3, 0, key_release, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);

	free_2d_array(game.map);
	free(game.no_path);
	free(game.so_path);
	free(game.we_path);
	free(game.ea_path);
	mlx_destroy_window(game.mlx, game.win);

	return (0);
}
