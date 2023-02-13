/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:43:27 by doykim            #+#    #+#             */
/*   Updated: 2023/02/09 13:01:22 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_wall(t_game *game, t_ray *ray, int x)
{
	t_img	texture_img;

	if (ray->side == 1 && ray->step_y < 0)
		texture_img = game->img_no;
	else if (ray->side == 1)
		texture_img = game->img_so;
	else if (ray->step_x > 0)
		texture_img = game->img_ea;
	else
		texture_img = game->img_we;
	calculate_line(game, ray, &texture_img);
	draw_img(game, ray, &texture_img, x);
}

void	calculate_line(t_game *game, t_ray *ray, t_img *texture_img)
{
	int	lineheight;

	if (ray->side == 0)
		ray->wall_x = game->player.y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		ray->wall_x = game->player.x + ray->perp_wall_dist * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->texture_x = (int)(ray->wall_x * (double)texture_img->line_len / 4);
	if (ray->side == 0 && ray->ray_dir_x < 0)
		ray->texture_x = texture_img->line_len / 4 - ray->texture_x - 1;
	if (ray->side == 1 && ray->ray_dir_y > 0)
		ray->texture_x = texture_img->line_len / 4 - ray->texture_x - 1;
	lineheight = (int)(HEIGHT / ray->perp_wall_dist);
	ray->drawstart = (-lineheight / 2) + (HEIGHT / 2);
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = (lineheight / 2) + (HEIGHT / 2);
	if (ray->drawend >= HEIGHT)
		ray->drawend = HEIGHT;
	ray->step = (double)texture_img->line_len / 4 / lineheight;
	ray->texture_pos = (ray->drawstart - HEIGHT / 2 + \
			lineheight / 2) * ray->step;
}

void	draw_img(t_game *game, t_ray *ray, t_img *texture_img, int x)
{
	int	y;
	int	pixel;

	y = 0;
	while (y < HEIGHT)
	{
		pixel = (y * game->image->line_len / 4) + x;
		if (y < ray->drawstart)
			game->image->data[pixel] = game->ceil;
		else if (y < ray->drawend)
		{
		ray->texture_y = (int)ray->texture_pos \
			& (texture_img->line_len / 4 - 1);
		game->image->data[pixel] = \
			texture_img->data[ray->texture_y * texture_img->line_len / 4 + \
			ray->texture_x];
		ray->texture_pos += ray->step;
		}
		else
			game->image->data[pixel] = game->floor;
		y++;
	}
}
