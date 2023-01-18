/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:19:27 by doykim            #+#    #+#             */
/*   Updated: 2023/01/17 21:32:02 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_file(int ac, char **av)
{
	char	buff[1024];
	int		fd;

	check_argument(ac, av);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error_exit(1);
	read(fd, buff, 1024);
	printf("%s", buff);
	check_element(buff);
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
	if (i <= 5)
		error_exit(1);
	if (!ft_strnstr(av[1], "maps/", 5))
		error_exit(1);
	if (!ft_strnstr(av[1] + i, ".cub\0", 5))
		error_exit(1);
}

void	check_element(char *buff)
{
	char	**temp;
	int		i;

	temp = ft_split(buff, '\n');
	i = 0;
	while (temp[i])
		printf("%s\n", temp[i++]);
	printf("%d\n", i);
}
