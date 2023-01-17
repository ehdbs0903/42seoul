/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:54:12 by jungeun           #+#    #+#             */
/*   Updated: 2023/01/15 00:57:18 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_join_and_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buf);
	return (temp);
}

void	set_heredoc_input(t_exec_token *token, t_env *env_list, int len)
{
	int		i;
	t_list	*in;

	i = 0;
	while (i < len)
	{
		in = token[i].parser_token->in;
		while (in != NULL)
		{
			if (ft_strncmp(in->content, "<<", 3) == 0)
			{
				get_infile(g_info.heredoc_cnt, in->next->content, env_list, 0);
				g_info.heredoc_cnt++;
			}
			in = in->next->next;
		}
		i++;
	}
}

void	get_infile(int num, char *limiter, t_env *env_list, int fd)
{
	pid_t	pid;
	int		status;
	char	*filename;

	pid = fork();
	if (pid == -1)
		error_return("fork error\n");
	if (pid == 0)
	{
		signal(SIGINT, heredoc_sig_handler);
		filename = ft_join_and_free("/tmp/", ft_itoa(num));
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		free(filename);
		if (fd == -1)
			error_exit("open error\n", 1);
		filename = heredoc_child_process(limiter, env_list);
		ft_putstr_fd(filename, fd);
		close(fd);
		exit(0);
	}
	else
	{
		signal(SIGINT, SIG_IGN);
		wait(&status);
	}
}

static char	*ft_join_and_free2(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

char	*heredoc_child_process(char *limiter, t_env *env_list)
{
	char	*line;
	char	*join_line;

	line = readline("> ");
	join_line = ft_strdup("");
	while (line)
	{
		if (ft_strncmp(line, limiter, ft_strlen(limiter) + 1) == 0)
		{
			free(line);
			break ;
		}
		line = replace_env_heredoc_exit_status(line);
		line = replace_env_heredoc(line, env_list);
		join_line = ft_join_and_free2(join_line, line);
		join_line = ft_join_and_free2(join_line, "\n");
		free(line);
		line = readline("> ");
	}
	return (join_line);
}
