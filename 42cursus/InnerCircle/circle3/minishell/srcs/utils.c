/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:57:43 by doykim            #+#    #+#             */
/*   Updated: 2022/12/23 03:19:50 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int iscmd(char *str)
{
	if (ft_strncmp(str, "echo", 4) == 0)
		return TRUE;
	else if (ft_strncmp(str, "cd", 2) == 0)
		return TRUE;
	else if (ft_strncmp(str, "pwd", 3) == 0)
		return TRUE;
	else if (ft_strncmp(str, "export", 6) == 0)
		return TRUE;
	else if (ft_strncmp(str, "unset", 5) == 0)
		return TRUE;
	else if (ft_strncmp(str, "env", 3) == 0)
		return TRUE;
	else if (ft_strncmp(str, "exit", 4) == 0)
		return TRUE;
	return FALSE;
}

