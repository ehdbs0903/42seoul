/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:39:29 by hajeong           #+#    #+#             */
/*   Updated: 2023/01/14 18:47:40 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	make_token(t_exec_token **token, char *cmd, int *len)
{
	t_list			*lexer_token;
	t_parser_token	*parser_token;
	int				code;

	lexer_token = NULL;
	code = parsing_error_handle(parsing(&lexer_token, cmd, g_info.env_list), \
			cmd);
	if (code != 0)
		return (code);
	*len = parser_token_size(lexer_token);
	parser_token = init_parser_token(*len);
	if (parser_token == NULL)
		clear_lexer_and_exit(&lexer_token);
	make_parser_token(&lexer_token, parser_token);
	sort_redirection(parser_token, *len);
	*token = make_exec_token(parser_token, token, *len);
	if (*token == NULL)
		clear_parser_and_exit(parser_token, *len);
	return (0);
}
