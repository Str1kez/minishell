/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:50:11 by tnessrou          #+#    #+#             */
/*   Updated: 2021/12/13 19:30:32 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	is_key(char c)
{
	return (c == '_' || ft_isalnum(c));
}

static char	*find_env(char *exp, t_env *env_list)
{
	while (env_list)
	{
		if (!ft_strcmp(exp, env_list->key))
		{
			cleaning(&exp);
			return (ft_strdup(env_list->value));
		}
		env_list = env_list->next;
	}
	cleaning(&exp);
	return (ft_strdup(""));
}

char	*dollar(char *str, int *i, t_env *env_list)
{
	int		help;
	char	*before;
	char	*env_exp;
	char	*after;

	help = *i;
	(*i)++;
	while (str[*i] && is_key(str[*i]))
		(*i)++;
	if (*i == help + 1)
		return (str);
	before = ft_substr(str, 0, help);
	env_exp = ft_substr(str, help + 1, *i - help - 1);
	after = ft_strdup(str + *i);
	env_exp = find_env(env_exp, env_list);
	(*i) = help + ft_strlen(env_exp);
	cleaning(&str);
	str = ft_strjoin(before, env_exp);
	cleaning(&before);
	cleaning(&env_exp);
	env_exp = ft_strjoin(str, after);
	cleaning(&str);
	cleaning(&after);
	printf("\n%c_%d\n", env_exp[*i], *i);
	return (env_exp);
}
