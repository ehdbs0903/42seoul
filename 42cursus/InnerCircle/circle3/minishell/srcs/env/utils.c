/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:41:55 by hajeong           #+#    #+#             */
/*   Updated: 2023/01/14 18:55:34 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_value(t_env *env_list, char *key)
{
	t_env	*temp;

	if (!key)
		return (NULL);
	temp = env_list;
	while (temp)
	{
		if (ft_strncmp(temp->key, key, ft_strlen(key) + 1) == 0)
			return (temp->value);
		temp = temp->next;
	}
	return (NULL);
}

void	free_env_list(t_env **env_list)
{
	t_env	*temp;

	if (!env_list)
		return ;
	while (*env_list)
	{
		temp = (*env_list)->next;
		free((*env_list)->key);
		free((*env_list)->value);
		free(*env_list);
		*env_list = temp;
	}
}
