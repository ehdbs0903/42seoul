/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <daykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:43:37 by doykim            #+#    #+#             */
/*   Updated: 2022/11/01 16:35:58 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	exit_game(int n)
{
	if (n == 1)
	{
		ft_printf("Error");
		exit(1);
	}
	else if (n == 0)
	{
		ft_printf("Success");
		exit(0);
	}
	else if (n == -1)
	{
		ft_printf("Fail");
		exit(0);
	}
	else
		exit(0);
}

static	int	check_argument(int ac, char **av)
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

static	void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->width = 0;
	game->height = 0;
	game->c_cnt = 0;
	game->e_cnt = 0;
	game->p_cnt = 0;
	game->m_cnt = 0;
	game->e_flag = 0;
	init_img(game);
}

static	int	x_exit(int n)
{
	n = 0;
	exit(n);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (check_argument(ac, av) == -1)
		exit_game(1);
	init_game(&game);
	read_map(av[1], &game);
	check_map(&game);
	game.win = mlx_new_window(game.mlx, game.width * 50, game.height * 50,
			"mlx 42");
	set_map_img(&game);
	mlx_string_put(game.mlx, game.win, 10, 20, -1, "0");
	mlx_hook(game.win, 2, 0, key_press, &game);
	mlx_hook(game.win, 17, 0, x_exit, &game);
	mlx_loop(game.mlx);
	return (0);
}
