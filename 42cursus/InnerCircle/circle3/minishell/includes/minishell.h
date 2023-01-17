/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:44:45 by hajeong           #+#    #+#             */
/*   Updated: 2023/01/14 19:01:48 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <signal.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libs/libft/libft.h"

# define NORMAL_STRING 0
# define DOUBLE_QUOTE 1
# define SINGLE_QUOTE 2
# define BLANK 3
# define PIPE 4
# define REDIR_IN 5
# define REDIR_HEREDOC 6
# define REDIR_OUT 7
# define REDIR_DOUBLE_OUT 8
# define AFTER_HEREDOC 9
# define AFTER_HEREDOC_DQ 10
# define AFTER_HEREDOC_SQ 11

// parsing_error_code
# define ODD_QUOTE_ERROR 1
# define NO_STR_AFTER_REDIR_ERROR 2
# define DOUBLE_PIPE_ERROR 3

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_parser_token
{
	t_list	*cmd;
	t_list	*in;
	t_list	*out;
}	t_parser_token;

typedef struct s_exec_token
{
	t_parser_token	*parser_token;
	char			**cmd;
	int				heredoc_num;
}	t_exec_token;

typedef struct s_info
{
	t_env	*env_list;
	int		exit_status;
	int		heredoc_cnt;
}	t_info;

t_info	g_info;

// lexer
void			free_temp_clear_and_exit(t_list **lexer_token, char *temp);
void			clear_lexer_and_exit(t_list **lexer_token);
void			lexer(char *str, t_list **lexer_token);
void			labeling(t_list *lexer_token);
void			labeling_after_heredoc(t_list *lexer_token);
int				check_odd_quote(t_list *lexer_token);

//parser
char			*join_env(char *before, char *value, char *after);
char			*join_env_free(char *before, char *value, char *after);
void			replace_env(t_list *lexer_token, t_env *env_list);
void			remove_quote(t_list **lexer_token);
void			merge_string(t_list **lexer_token);
void			delete_blank(t_list **lexer_token);
int				check_redirection(t_list *lexer_token);
int				check_double_pipe(t_list *lexer_token);
int				parsing(t_list **lexer_token, char *cmd, t_env *env_list);
int				parsing_error_handle(int code, char *cmd);
int				parser_token_size(t_list *lexer_token);
t_parser_token	*init_parser_token(int size);
void			make_parser_token(t_list **lexer_token, t_parser_token *\
				parser_token);
void			free_parser_token(t_parser_token *parser_token, int len);
int				make_token(t_exec_token **token, char *cmd, int *len);
void			replace_env_exit_status(t_list *l_tok);

void			sort_redirection(t_parser_token *parser_token, int len);
void			clear_parser_and_exit(t_parser_token *parser_token, int len);

// exec_token
t_exec_token	*make_exec_token(t_parser_token *parser_token, t_exec_token \
				**exec_token, int len);
char			**make_2d_array(t_list *cmd_list);
void			free_all_token(t_exec_token *exec_token, t_parser_token \
				*parser_token, int len);

// env
t_env			*init_env_list(char **envp);
t_env			*make_env_node(char *key, char *value);
void			env_list_add_node(t_env **list, t_env *node);
void			free_env_list(t_env **env_list);

char			*get_env_value(t_env *env_list, char *key);

// utils
void			setting_signal(void);
void			sig_handler(int signal);
void			heredoc_sig_handler(int signal);
void			set_echoctl_off(void);
void			set_echoctl_on(void);

void			free_2d_array(char **str);
void			error_exit(char *str, int status);
int				error_return(char *str);
int				free_init_exec_info(pid_t **pids, int ***fds, int i);
void			rm_all_heredoc_file(void);
char			*read_cmd(void);

// exec_builtin
int				is_builtin(t_exec_token *token);
void			exec_builtin(t_exec_token *token, t_env *env_list);

// env
int				ft_env(char **cmd, t_env *env_list);
void			print_env_list(t_env *env_list);
void			print_env_list_with_export(t_env *env_list);

// export
int				ft_export(char **cmd, t_env *env_list);
void			execute_export(char *key, char *value, t_env *env_list);
int				is_key_in_env_list(char *key, t_env *env_list);
int				is_valid_format_key(char *key);
void			update_value(char *key, char *value, t_env **env_list);

// unset
int				ft_unset(char **cmd, t_env *env_list);
void			delete_node(char *key, t_env **env_list);
t_env			*get_node(char *key, t_env *env_list);

// echo
int				ft_echo(char **cmd);

// cd
int				ft_cd(char **cmd, int flag);

// exec_cmd
void			exec_cmd(t_exec_token *token, t_env *env_list, int len);
void			run_execve_cmd(char **cmd_list, t_env *env_list);
char			**convert_env_list_to_str_list(t_env *env_list);
void			join_key_and_value(char **env_str, t_env *env_list);
char			*get_path(char *cmd, char **env);

// redir
void			set_redir(t_exec_token *token);
char			*replace_env_heredoc(char *str, t_env *env_list);
char			*replace_env_heredoc_exit_status(char *str);
void			set_redir_in(t_exec_token *token, char *redir_sign, \
				char *filename);
void			set_redir_out(char *redir_sign, char *filename);

// heredoc
void			set_heredoc_input(t_exec_token *token, t_env *env_list, \
				int len);
void			get_infile(int num, char *limiter, t_env *env_list, int fd);
char			*heredoc_child_process(char *limiter, t_env *env_list);
char			*ft_join_and_free(char *buffer, char *buf);
// exec_pipe
int				init_exec_info(pid_t **pids, int ***fds, int len);
void			close_all_fds(int **fds, int len);
void			wait_all_childs(pid_t *pids, int len);
void			exec_pipe(t_exec_token *token, pid_t *pids, int **fds, int len);
void			child_process(int **fds, int i, t_exec_token token, int len);

int				ft_exit(char **cmd);
int				ft_pwd(char **cmd);

#endif
