/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:57:51 by hajeong           #+#    #+#             */
/*   Updated: 2023/01/14 18:49:51 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parsing(t_list **lexer_token, char *cmd, t_env *env_list)
{
	lexer(cmd, lexer_token);
	labeling(*lexer_token);
	labeling_after_heredoc(*lexer_token);
	if (check_odd_quote(*lexer_token))
	{
		ft_lstclear(lexer_token, free);
		return (ODD_QUOTE_ERROR);
	}
	replace_env_exit_status(*lexer_token);
	replace_env(*lexer_token, env_list);
	remove_quote(lexer_token);
	merge_string(lexer_token);
	delete_blank(lexer_token);
	if (check_redirection(*lexer_token))
	{
		ft_lstclear(lexer_token, free);
		return (NO_STR_AFTER_REDIR_ERROR);
	}
	if (check_double_pipe(*lexer_token))
	{
		ft_lstclear(lexer_token, free);
		return (DOUBLE_PIPE_ERROR);
	}
	return (0);
}

int	parsing_error_handle(int code, char *cmd)
{
	if (code == 0)
		return (0);
	if (code == ODD_QUOTE_ERROR)
		printf("odd quote is not allowed!\n");
	else if (code == NO_STR_AFTER_REDIR_ERROR)
		printf("no string after redirection!\n");
	else if (code == DOUBLE_PIPE_ERROR)
		printf("error near pipe!\n");
	free(cmd);
	return (code);
}
