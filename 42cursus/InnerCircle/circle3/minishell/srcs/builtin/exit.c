/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:56:50 by jungeun           #+#    #+#             */
/*   Updated: 2023/01/14 19:02:46 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isdigit_str(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (!ft_isdigit(str[idx]))
			return (0);
		idx++;
	}
	return (1);
}

void	ft_exit_errcode(void)
{
	ft_putstr_fd("exit\n", STDERR_FILENO);
	exit(g_info.exit_status);
}

int	ft_exit(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i] != NULL)
		i++;
	if (i == 1)
		ft_exit_errcode();
	else if (i == 2 && ft_isdigit_str(cmd[1]))
		g_info.exit_status = ft_atoi(cmd[1]);
	else if (i > 2 && ft_isdigit_str(cmd[1]))
	{
		ft_putstr_fd("exit\n", STDERR_FILENO);
		printf("exit : too many arguments\n");
		g_info.exit_status = 1;
		return (0);
	}
	else
	{
		printf("exit : numeric argument required\n");
		g_info.exit_status = 255;
		exit(g_info.exit_status & 255);
	}
	ft_exit_errcode();
	return (0);
}
