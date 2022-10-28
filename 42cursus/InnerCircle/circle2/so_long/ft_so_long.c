/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <daykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:43:37 by doykim            #+#    #+#             */
/*   Updated: 2022/10/28 18:45:30 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	print_error(int n)
{
	ft_printf("Error");
	exit(n);
}

int	check_argument(int ac, char **av)
{
	int	i;

	if (ac != 2)
		return (-1);
	i = ft_strlen(av[1]) - 4;
	if (i <= 0)
		return (-1);
	if (!ft_strnstr(av[1] + i, ".ber", 4))
		return (-1);
	return (0);
}

void	init_game(t_game *game)
{
	game->width = 0;
	game->height = 0;
	game->c_cnt = 0;
	game->e_cnt = 0;
	game->p_cnt = 0;
	game->e_flag = 0;
	init_img(game);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (check_argument(ac, av) == -1)
		print_error(1);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.width * 50, game.height * 50,
			"mlx 42");
	init_game(&game);
	read_map(av[1], &game);
	init_img(&game);
	set_map_img(&game);
	mlx_hook(game.win, X_EVENT_KEY_RELEASE, 0, &key_press, &game);
	mlx_loop(game.mlx);
	return (0);
}
