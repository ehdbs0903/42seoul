/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:39:00 by sanghan           #+#    #+#             */
/*   Updated: 2023/02/02 20:17:17 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void verLine (t_game *game, int x, int y1, int y2, int color)
{
    int temp;

    temp = y1;
	while (temp <= y2)
    {
        mlx_pixel_put(game->mlx, game->win, x, temp, color);
        temp++;
    }
}

int raycasting(t_game *game)
{
    int x;

    x = 0;
    while (x < WIDTH)
    {
        double cameraX = (2 * x / (double)(WIDTH)) - 1;

        double rayDirectionX = game->player.dir_x + game->plane_x * cameraX;
        double rayDirectionY = game->player.dir_y + game->plane_y * cameraX;

        int mapX = (int)(game->player.x);
        int mapY = (int)(game->player.y);

        double sideDistX;
        double sideDistY;

        double deltaDistX = fabs(1 / rayDirectionX);
        double deltaDistY = fabs(1 / rayDirectionY);
        double perpWallDist;

        int stepX;
        int stepY;

        int hit = 0;
        int side;

		if (rayDirectionX < 0)
        {
            stepX = -1;
            sideDistX = (game->player.x - mapX) * deltaDistX;
        }
        else
        {
            stepX = 1;
            sideDistX = (mapX + 1.0 - game->player.x) * deltaDistX;
        }
        if (rayDirectionY < 0)
        {
            stepY = -1;
            sideDistY = (game->player.y - mapY) * deltaDistY;
        }
        else
        {
            stepY = 1;
            sideDistY = (mapY + 1.0 - game->player.y) * deltaDistY;
        }

        while (hit == 0)
        {
            if (sideDistX < sideDistY)
            {
                sideDistX += deltaDistX;
                mapX += stepX;
				side = 0;
			}
            else
            {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;  
			}
			////////////////////////////////
            if (game->map[mapX][mapY] == '1')
                hit = 1;
        }
        if (side == 0)
            perpWallDist = (mapX - game->player.x + (1 - stepX) / 2) / rayDirectionX;
        else
            perpWallDist = (mapY - game->player.y + (1 - stepY) / 2) / rayDirectionY;
        int lineHeight = (int)(HEIGHT / perpWallDist);
        
		int drawStart = (-lineHeight / 2) + (HEIGHT / 2);
        if (drawStart < 0)
            drawStart = 0;
        int drawEnd = (lineHeight / 2) + (HEIGHT / 2);
        if (drawEnd >= HEIGHT)
            drawEnd = HEIGHT - 1;

        int color;
        if (game->map[mapX][mapY] == '1')
            color = 0xFFFFFF;

        if (side == 1)
            color = color / 2;

        verLine(game, x, drawStart, drawEnd, color);
        x++;
    }
	return(0);
}
