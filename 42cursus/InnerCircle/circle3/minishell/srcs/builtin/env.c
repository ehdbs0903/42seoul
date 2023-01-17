/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:56:36 by jungeun           #+#    #+#             */
/*   Updated: 2023/01/14 18:56:40 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(char **cmd, t_env *env_list)
{
	if (cmd[1] != NULL)
		return (error_return("too many arguments\n"));
	print_env_list(env_list);
	return (0);
}

void	print_env_list(t_env *env_list)
{
	t_env	*temp;

	temp = env_list;
	while (temp)
	{
		printf("%s=%s\n", temp->key, temp->value);
		temp = temp->next;
	}
}

void	print_env_list_with_export(t_env *env_list)
{
	t_env	*temp;

	temp = env_list;
	while (temp)
	{
		printf("declare -x %s", temp->key);
		if (temp->value != NULL)
			printf("=\"%s\"", temp->value);
		printf("\n");
		temp = temp->next;
	}
}
