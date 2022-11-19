/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 20:34:28 by doykim            #+#    #+#             */
/*   Updated: 2022/11/01 16:06:34 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	put_img(t_game *game, void *img, int w, int h)
{
	mlx_put_image_to_window(game->mlx, game->win, img, w * 50, h * 50);
}

void	draw_text(t_game *game)
{
	char	*temp;

	put_img(game, game->wall, 0, 0);
	temp = ft_itoa(game->m_cnt);
	mlx_string_put(game->mlx, game->win, 10, 20, -1, temp);
	free(temp);
	ft_printf("move count: %d\n", game->m_cnt);
}
