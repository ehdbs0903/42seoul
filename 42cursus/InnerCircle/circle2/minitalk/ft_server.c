/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <daykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:59:16 by doykim            #+#    #+#             */
/*   Updated: 2022/09/13 23:51:49 by doykim           ###   ########.fr       */
/*   Updated: 2022/09/13 22:11:25 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

int	main(int argc, char **argv)
{
	int	pid;

	pid = getpid();
	ft_printf("server pid: %d\n", pid);
	kill(ft_atoi(argv[1]), SIGKILL);
	return (0);
}
