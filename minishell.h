/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:34:57 by tnessrou          #+#    #+#             */
/*   Updated: 2021/12/11 17:51:23 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}				t_env;

char	*quotes(char *str, int *i);
char	*double_quotes(char *str, int *i, t_env *env_list);
// char	*slash_in_quotes(char *str);
char	*slash(char *str, int *i);
char	*dollar(char *str, int *i, t_env *env_list);
void	cleaning(char **data);
t_env	*new_env(char *str);
void	del_env(t_env *node);
void	clean_env(t_env **env);
t_env	*init_env(char **envp);

#endif