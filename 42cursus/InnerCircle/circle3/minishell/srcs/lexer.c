/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:53:06 by doykim            #+#    #+#             */
/*   Updated: 2022/12/22 20:55:34 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void lexer(char *str, t_list **lexer_tokens)
{
	int i;

	i = 0;
	if (str[0] == '\0')
		return ;
	else if (str[0] == '\"' || str[0] == '\'')
	{
		i = 1;
		while (str[i] != '\0' && str[i] != str[0]) // 홀수 따옴표 갯수는 다음 단계에서 처리
			i++;
		if (str[i] == '\0')
			return ft_lstadd_back(lexer_tokens, ft_lstnew(ft_substr(str, 0, i+1)));
	}
	else if ((str[0] == '<' && str[1] == '<') || (str[0] == '>' && str[1] == '>'))
		i++;
	else if (str[0] == '<' || str[0] == '>' || str[0] == '|')
		;
	else if (ft_strchr("\t\n\v\f\r ", str[0]))
		return lexer(str+1, lexer_tokens);
	else {
		while (!ft_strchr("|\'\"><\t\n\v\f\r ", str[i + 1]))
			i++;
	}
	ft_lstadd_back(lexer_tokens, ft_lstnew(ft_substr(str, 0, i+1)));
	lexer(str+i+1, lexer_tokens);
}
