/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <daykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 22:00:45 by doykim            #+#    #+#             */
/*   Updated: 2022/09/13 23:41:17 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

int main(int argc, char **argv)
{
	int pid;

	pid = getpid();
	ft_printf("client pid: %d\n", pid);
	while(1)
	{
		ft_printf("running\n");
		sleep(5);
	}
	return (0);
}
