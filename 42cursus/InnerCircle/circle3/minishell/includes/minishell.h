/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:57:50 by doykim            #+#    #+#             */
/*   Updated: 2022/12/23 03:09:26 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libs/libft/libft.h"

# define TRUE 1
# define FALSE 0

# define CMD 1
# define WORD 2
# define PIPE 3
# define REDIRECT 4

typedef struct	s_parser_tokens
{
	t_list	*type;
	t_list	*cmd;
	t_list	*word;
	t_list	*pipe;
	t_list	*redirect;
}	t_parser_tokens;

void	lexer(char *str, t_list **lexer_tokens);

void	parser(t_list *lexer_token, t_parser_tokens *parser_tokens);

int iscmd(char *str);

#endif
