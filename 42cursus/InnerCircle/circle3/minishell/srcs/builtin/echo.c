/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:05:17 by sanghan           #+#    #+#             */
/*   Updated: 2023/01/14 18:56:21 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_nflag(char *str)
{
	int	i;

	if (str[0] != '-')
		return (0);
	if (str[1] != 'n')
		return (0);
	i = 1;
	while (str[i] == 'n')
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

int	ft_echo(char **cmd)
{
	int	i;
	int	nflag;

	nflag = 0;
	i = 1;
	if (cmd[i] != NULL && is_nflag(cmd[i]))
	{
		nflag = 1;
		while (cmd[i] != NULL && is_nflag(cmd[i]))
			i++;
	}
	while (cmd[i] != NULL)
	{
		ft_putstr_fd(cmd[i], STDOUT_FILENO);
		i++;
		if (cmd[i] == NULL)
			break ;
		ft_putstr_fd(" ", STDOUT_FILENO);
	}
	if (!nflag)
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (0);
}
