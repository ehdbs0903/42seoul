/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <daykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:44:29 by doykim            #+#    #+#             */
/*   Updated: 2022/10/05 21:27:26 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include "mlx/mlx.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>

typedef struct s_game
{
	int		width;
	int		height;
	char	*map;
	void	*mlx;
	void	*win;
	void	*grass;
	void	*rock;
	void	*blue_orb;
	void	*red_orb;
}	t_game;

void	print_error();
int		check_argument(int ac, char **av);
void	init_img(t_game *game);
void	set_img(t_game *game);
void	read_map(char *filename, t_game *game);

#endif
