/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 16:57:32 by aroblin           #+#    #+#             */
/*   Updated: 2018/12/18 04:59:38 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <fcntl.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <grp.h>
# include <uuid/uuid.h>
# include "../libft/libft.h"
# include <signal.h>
# include <limits.h>

typedef struct			s_d_env
{
	char				*cle;
	char				*value;
}						t_d_env;

int						read_prompt(const int fd, char **line);

void					ft_copy_list(t_list *src, t_list **dest);
char					**ft_strsplit_mod(char *s, char c);

void					make_env(char **env, t_list **envl);
void					tab_to_list(char **env, t_list **envl);
char					**list_to_tab(t_list *list);
void					shell_level(t_list **envl);

int						make_path(t_list **envl);
char					*check_path(char **path, char *command);

char					*detec_value(t_list *envl, char *cle);
int						detec_cle(t_list *envl, char *cle);
void					change_value(t_list *envl, char *cle, char *new_value);
void					create_var(t_list **envl, char *cle, char *value);

void					print_env(t_list *envl);

void					command_line(char **env, t_list **envl);
int						check_command(char *commd, t_list **envl, char **cop);
int						command_way(char *command,
						t_list *envl, char *copy, char **cop_command);
int						type_arg(char *copy, mode_t type, char **cop_command);
char					*bad_command(char *command);
char					*bad_command_env(char *command);
int						begin_by(char *command);
int						go_exe(char *cmd, char **tb, t_list **evl, char **env);
int						exe_root(char *cmd, char **tab, char **env);
int						detec_slh(char *cmd);

void					ft_cd(char **arg, t_list **envl);
void					change_path_link(t_list *envl,
						char *arg, char *buf_pwd);
void					change_path(t_list *envl, char *arg, char *buf_pwd);
char					*new_arg(char *pwd);
int						nb_return(char *arg);
void					manag_var(t_list *envl, char *buf_pwd,
						struct stat buf_link);
char					**arg_for_env(char **tab, int i);
void					ft_pars_env(char **tab, t_list **envl);
char					*root_dir(char *arg, t_list *envl,
						char **part, int *cap);
char					*make_new_arg(char **part, t_list *envl,
						int *cap, char *arg);
void					check_type(char *new, int *cap, char *arg);
void					error_cd(int err, char *arg);
char					*sup_ret_root(char *new, t_list *envl);
char					*root_dir(char *arg, t_list *envl,
						char **part, int *cap);

void					bt_exit(char **tab, t_list **envl);

void					exe_setenv(char **tab, t_list **envl);
int						ft_setenv(t_list *envl, char *cle, char *value);
void					exe_unsetenv(char **tab, t_list **envl);
void					ft_unsetenv(t_list **envl, char *cle);

void					exe_command(char **tab, char **env, char *command);

void					echo(char **tab, t_list **envl);

char					**expansion_dollar(char **tab, t_list *envl);
char					**expansion_tilde(char **tab, t_list *envl);

int						option(char **arg, char **opt);
int						check_option(char *option, char letter);
int						check_final_option(char *option, char letter);
int						check_bad_option(char *option, char letter);
int						check_bad(char *option, char letter, char let);

void					tab_del(char **tab);
void					del(void *content, size_t size);

void					usage_env(void);
void					usage_cd(void);

char					*ret_pwd(t_list *envl);
void					error_malloc(void);
void					error_read(void);
void					error_fork(void);
int						error_open(void);
#endif
