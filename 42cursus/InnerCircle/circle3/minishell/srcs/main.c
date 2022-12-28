/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:51:22 by doykim            #+#    #+#             */
/*   Updated: 2022/12/23 03:22:04 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main() {
	t_list *lexer_token = NULL;
	lexer("  echo cat <<eof >file1 && cat file1 && abc || wc <file1 | cat >file2 \"$asd 43 rew", &lexer_token);
	t_list *temp = lexer_token;
	int node_index = 0;
	while (temp != NULL)
	{
		printf("%2d 번째 노드 : [%s]\n", node_index++, temp->content);
		temp = temp->next;
	}
	printf("%d %d\n", node_index, ft_lstsize(lexer_token));

	//ft_lstadd_back(&temp, ft_lstnew("123"));
	//printf("%s", temp->content);
	
	t_parser_tokens parser_tokens;
	parser(lexer_token, &parser_tokens);
	//parser_tokens.cmd = NULL;
	//ft_lstadd_back(&parser_tokens.cmd, ft_lstnew("123"));
	//printf("%s\n", parser_tokens.cmd->content);
	t_list *temp2 = parser_tokens.type;
	int i = 0;
	while (temp2 != NULL)
	{
		printf("%d : %s\n", i++, temp2->content);
		temp2 = temp2->next;
	}
	return (0);
}
