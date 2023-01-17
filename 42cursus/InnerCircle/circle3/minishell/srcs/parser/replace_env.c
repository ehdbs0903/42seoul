/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 09:58:22 by hajeong           #+#    #+#             */
/*   Updated: 2023/01/14 18:50:27 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_env(char *before, char *value, char *after)
{
	char	*str;
	char	*join;

	if (!value)
		value = "";
	if (!before | !value | !after)
		return (0);
	str = (char *)malloc(sizeof(char) * (ft_strlen(before) \
	+ ft_strlen(value) + ft_strlen(after) + 1));
	if (!str)
		return (NULL);
	join = str;
	while (*before && *before != '$')
		*join++ = *before++;
	while (*value)
		*join++ = *value++;
	while (*after)
		*join++ = *after++;
	*join = '\0';
	return (str);
}

char	*join_env_free(char *before, char *value, char *after)
{
	char	*str;
	char	*join;
	char	*temp;

	if (!value)
		value = ft_strdup("");
	if (!before | !value | !after)
		return (0);
	str = (char *)malloc(sizeof(char) * (ft_strlen(before) \
	+ ft_strlen(value) + ft_strlen(after) + 1));
	if (!str)
		return (NULL);
	join = str;
	while (*before && *before != '$')
		*join++ = *before++;
	temp = value;
	while (*temp)
		*join++ = *temp++;
	while (*after)
		*join++ = *after++;
	*join = '\0';
	free(value);
	return (str);
}

void	replace_env(t_list *l_tok, t_env *envlst)
{
	char	*key;
	char	*key_end;
	char	*str;

	while (l_tok != NULL)
	{
		while (l_tok != NULL && l_tok->label >= AFTER_HEREDOC)
			l_tok = l_tok->next;
		if (l_tok != 0 && l_tok->label != 2 && ft_strchr(l_tok->content, '$'))
		{
			key = ft_strchr(l_tok->content, '$');
			key_end = key + 1;
			while (ft_isalnum(*key_end))
				key_end++;
			key = ft_substr(key, 1, (int)(key_end - key - 1));
			str = join_env(l_tok->content, get_env_value(envlst, key), key_end);
			free(l_tok->content);
			l_tok->content = str;
			free(key);
			if (l_tok->content == NULL)
				clear_lexer_and_exit(&l_tok);
		}
		if (l_tok && (!ft_strchr(l_tok->content, '$') || l_tok->label == 2))
			l_tok = l_tok->next;
	}
}

void	replace_env_exit_status(t_list *l_tok)
{
	char	*key;
	char	*e;
	char	*str;

	while (l_tok != NULL)
	{
		while (l_tok != NULL && l_tok->label >= AFTER_HEREDOC)
			l_tok = l_tok->next;
		if (l_tok != 0 && l_tok->label != 2 && ft_strnstr(l_tok->content, \
		"$?", ft_strlen(l_tok->content)))
		{
			key = ft_strchr(l_tok->content, '$');
			e = key + 2;
			key = ft_substr(key, 1, (int)(1));
			str = join_env_free(l_tok->content, ft_itoa(g_info.exit_status), e);
			free(l_tok->content);
			l_tok->content = str;
			free(key);
			if (l_tok->content == NULL)
				clear_lexer_and_exit(&l_tok);
		}
		if (l_tok && (!(ft_strnstr(l_tok->content, "$?", \
		ft_strlen(l_tok->content))) || l_tok->label == 2))
			l_tok = l_tok->next;
	}
}
