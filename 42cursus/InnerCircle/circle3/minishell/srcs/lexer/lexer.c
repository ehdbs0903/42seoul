/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 09:58:22 by hajeong           #+#    #+#             */
/*   Updated: 2023/01/14 18:51:51 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lexer(char *str, t_list **lexer_token)
{
	int		i;
	char	*temp;
	t_list	*new;

	while (str[0] != '\0')
	{
		i = 0;
		if (str[0] == '\"' || str[0] == '\'')
			while (str[++i] != '\0' && str[i] != str[0])
				;
		else if (ft_strncmp(str, "<<", 2) == 0 || ft_strncmp(str, ">>", 2) == 0)
			i++;
		else if (ft_strchr("\t\n\v\f\r ", str[0]))
			;
		else if (str[0] != '<' && str[0] != '>' && str[0] != '|')
			while (!ft_strchr("|\'\"><\t\n\v\f\r ", str[i + 1]))
				i++;
		temp = ft_substr(str, 0, i + 1);
		new = ft_lstnew(temp);
		if (temp == NULL || new == NULL)
			free_temp_clear_and_exit(lexer_token, temp);
		ft_lstadd_back(lexer_token, new);
		str += i + 1;
	}
}
