/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_utils3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 20:34:28 by doykim            #+#    #+#             */
/*   Updated: 2022/10/28 20:36:35 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	put_img(t_game *game, void *img, int w, int h)
{
	mlx_put_image_to_window(game->mlx, game->win, img, w * 50, h * 50);
}
