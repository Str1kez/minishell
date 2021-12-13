/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:02:17 by tnessrou          #+#    #+#             */
/*   Updated: 2021/12/13 21:05:00 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*control(char *str, int *i, t_env *env_list)
{
	while (str[*i] && str[*i] != '"')
	{
		if (str[*i] == '\\' && (str[*i + 1] == '"'
				|| str[*i + 1] == '$' || str[*i + 1] == '\\'))
			str = slash(str, i);
		else if (str[*i] == '$')
			str = dollar(str, i, env_list);
		else
			(*i)++;
	}
	return (str);
}

char	*quotes(char *str, int *i)
{
	int		help;
	char	*before;
	char	*now;
	char	*after;

	help = *i;
	(*i)++;
	while (str[*i] && str[*i] != '\'')
		(*i)++;
	before = ft_substr(str, 0, help);
	now = ft_substr(str, help + 1, *i - help - 1);
	after = ft_strdup(str + *i + 1);
	cleaning(&str);
	str = ft_strjoin(before, now);
	cleaning(&before);
	cleaning(&now);
	now = ft_strjoin(str, after);
	cleaning(&str);
	cleaning(&after);
	*i -= 2;
	return (now);
}

char	*double_quotes(char *str, int *i, t_env *env_list)
{
	int		help;
	char	*before;
	char	*now;
	char	*after;

	help = *i;
	(*i)++;
	str = control(str, i, env_list);
	before = ft_substr(str, 0, help);
	now = ft_substr(str, help + 1, *i - help - 1);
	after = ft_strdup(str + *i + 1);
	cleaning(&str);
	str = ft_strjoin(before, now);
	cleaning(&before);
	cleaning(&now);
	now = ft_strjoin(str, after);
	cleaning(&str);
	cleaning(&after);
	*i -= 2;
	return (now);
}
