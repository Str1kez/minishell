/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:29:48 by tnessrou          #+#    #+#             */
/*   Updated: 2021/12/10 21:05:13 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	del_env(t_env *node)
{
	free(node->key);
	free(node->value);
	free(node);
}

t_env	*new_env(char *str)
{
	t_env	*node;
	int		eq_index;

	node = (t_env *)malloc(sizeof(t_env));
	if (!node)
		return (NULL);
	eq_index = ft_strchr(str, '=') - str;
	node->key = ft_substr(str, 0, eq_index);
	node->value = ft_strdup(str + eq_index + 1);
	node->next = NULL;
	return (node);
}

void	push_env(t_env **env, t_env *new)
{
	if (!*env)
	{
		*env = new;
		return ;
	}
	while ((*env)->next)
		env = &((*env)->next);
	(*env)->next = new;
}

void	clean_env(t_env **env)
{
	t_env	*help;

	if (!*env)
		return ;
	while ((*env)->next)
	{
		help = *env;
		env = &((*env)->next);
		del_env(help);
	}
	del_env(*env);
}
