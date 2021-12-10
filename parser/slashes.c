/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slashes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:43:30 by tnessrou          #+#    #+#             */
/*   Updated: 2021/12/10 19:05:40 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// char	*slash_in_quotes(char *str)
// {
// 	int		i;
// 	int		count;
// 	char	*res;

// 	i = -1;
// 	count = 0;
// 	while (str[++i])
// 		if (str[i] == '\\')
// 			count++;
// 	if (!count)
// 		return (str);
// 	res = (char *)malloc(ft_strlen(str) + count + 1);
// 	i = -1;
// 	count = 0;
// 	while (str[++i])
// 	{
// 		res[i + count] = str[i];
// 		if (str[i] == '\\')
// 			res[i + ++count] = '\\';
// 	}
// 	res[i + count] = '\0';
// 	free(str);
// 	return (res);
// }

char	*slash(char *str, int *i)
{
	char	*before;
	char	*after;

	before = ft_substr(str, 0, *i);
	(*i)++;
	after = ft_strdup(str + *i);
	cleaning(&str);
	str = ft_strjoin(before, after);
	cleaning(&before);
	cleaning(&after);
	return (str);
}
