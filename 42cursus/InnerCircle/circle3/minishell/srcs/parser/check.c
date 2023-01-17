/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 09:58:22 by hajeong           #+#    #+#             */
/*   Updated: 2023/01/14 18:47:12 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_redirection(t_list *lexer_token)
{
	while (lexer_token != NULL)
	{
		if (REDIR_IN <= lexer_token->label \
		&& lexer_token->label <= REDIR_DOUBLE_OUT)
		{
			if (lexer_token->next == NULL \
			|| lexer_token->next->label != NORMAL_STRING)
			{
				return (1);
			}
		}
		lexer_token = lexer_token->next;
	}
	return (0);
}

int	check_double_pipe(t_list *lexer_token)
{
	if (lexer_token != NULL && lexer_token->label == PIPE)
		return (1);
	while (lexer_token != NULL)
	{
		if (lexer_token->label == PIPE)
		{
			if (lexer_token->next == NULL || lexer_token->next->label == PIPE)
			{
				return (1);
			}
		}
		lexer_token = lexer_token->next;
	}
	return (0);
}
