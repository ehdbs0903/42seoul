/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:42:35 by hajeong           #+#    #+#             */
/*   Updated: 2023/01/15 00:14:53 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*read_cmd(void)
{
	char	*cmd;

	set_echoctl_off();
	setting_signal();
	cmd = readline("minishell$ ");
	if (!cmd)
	{
		printf("\033[1A");
		printf("\033[11C");
		printf("exit\n");
		free_env_list(&(g_info.env_list));
		exit(0);
	}
	return (cmd);
}
