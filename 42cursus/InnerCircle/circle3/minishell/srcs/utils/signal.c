/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:43:40 by hajeong           #+#    #+#             */
/*   Updated: 2023/01/14 18:46:14 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	setting_signal(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
}

void	sig_handler(int signal)
{
	if (signal == SIGINT)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	heredoc_sig_handler(int signal)
{
	if (signal == SIGINT)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		exit(1);
	}
}

void	set_echoctl_off(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void	set_echoctl_on(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag |= (ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
