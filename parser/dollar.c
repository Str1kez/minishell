/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:50:11 by tnessrou          #+#    #+#             */
/*   Updated: 2021/12/10 17:53:02 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	is_key(char c)
{
	return (c == '_' || ft_isalnum(c));
}

char	*dollar(char *str, int *i)
{
	int		help;
	char	*before;
	char	*env_key;
	char	*after;

	help = *i;
	(*i)++;
	while (str[*i] && is_key(str[*i]))
		(*i)++;
	if (*i == help + 1)
		return (str);
	before = ft_substr(str, 0, help);
	env_key = ft_substr(str, help + 1, *i - help - 1);
	after = ft_strdup(str + *i + 1);
	cleaning(&str);
	str = ft_strjoin(before, env_key);
	cleaning(&before);
	cleaning(&env_key);
	env_key = ft_strjoin(str, after);
	cleaning(&str);
	cleaning(&after);
	(*i)--;
	return (env_key);
}
