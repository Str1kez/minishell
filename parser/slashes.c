/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slashes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:43:30 by tnessrou          #+#    #+#             */
/*   Updated: 2021/12/13 21:05:15 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
