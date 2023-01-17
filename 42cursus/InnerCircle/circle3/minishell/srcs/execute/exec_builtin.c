/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:52:35 by jungeun           #+#    #+#             */
/*   Updated: 2023/01/14 18:52:37 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(t_exec_token *token)
{
	char	*cmd;

	if (token->parser_token->cmd == NULL)
		return (0);
	cmd = token->parser_token->cmd->content;
	if (ft_strncmp(cmd, "env", 4) == 0 || \
		ft_strncmp(cmd, "export", 7) == 0 || \
		ft_strncmp(cmd, "unset", 6) == 0 || \
		ft_strncmp(cmd, "cd", 3) == 0 || \
		ft_strncmp(cmd, "echo", 5) == 0 || \
		ft_strncmp(cmd, "exit", 5) == 0 || \
		ft_strncmp(cmd, "pwd", 4) == 0)
		return (1);
	else
		return (0);
}

void	exec_builtin(t_exec_token *token, t_env *env_list)
{
	char	*cmd;
	int		status;
	int		flag;

	flag = 0;
	cmd = token->cmd[0];
	status = 0;
	if (ft_strncmp(cmd, "env", 4) == 0)
		status = ft_env(token->cmd, env_list);
	else if (ft_strncmp(cmd, "export", 7) == 0)
		status = ft_export(token->cmd, env_list);
	else if (ft_strncmp(cmd, "unset", 6) == 0)
		status = ft_unset(token->cmd, env_list);
	else if (ft_strncmp(cmd, "cd", 3) == 0)
		status = ft_cd(token->cmd, flag);
	else if (ft_strncmp(cmd, "pwd", 4) == 0)
		status = ft_pwd(token->cmd);
	else if (ft_strncmp(cmd, "echo", 5) == 0)
		status = ft_echo(token->cmd);
	else if (ft_strncmp(cmd, "exit", 9) == 0)
		status = ft_exit(token->cmd);
	g_info.exit_status = status;
}
