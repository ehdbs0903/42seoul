/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:19:27 by doykim            #+#    #+#             */
/*   Updated: 2023/01/19 19:18:03 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_file(int ac, char **av, t_game *game)
{
	char	buff[MAX_SIZE];
	char	**temp;
	int		fd;

	check_argument(ac, av);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error_exit(1);
	read(fd, buff, MAX_SIZE);
	temp = ft_split(buff, '\n');
	init_element(temp, game);
	free_2d_array(temp);
	close(fd);
}

void	check_argument(int ac, char **av)
{
	int		i;
	int		len;

	if (ac != 2)
		error_exit(1);
	len = ft_strlen(av[1]);
	i = len - 4;
	if (i <= 0)
		error_exit(1);
	if (!ft_strnstr(av[1] + i, ".cub\0", 5))
		error_exit(1);
}
