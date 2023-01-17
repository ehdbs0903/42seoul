/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:30:23 by hajeong           #+#    #+#             */
/*   Updated: 2023/01/09 20:10:50 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear_parser_and_exit(t_parser_token *parser_token, int len)
{
	free_parser_token(parser_token, len);
	free_env_list(&(g_info.env_list));
	exit(0);
}
