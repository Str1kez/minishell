/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:45:09 by tnessrou          #+#    #+#             */
/*   Updated: 2021/12/16 17:22:06 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	check_closed(char *str, int *i, char c)
{
	(*i)++;
	while (str[*i])
	{
		if (str[*i] == c)
			return (0);
		(*i)++;
	}
	return (1);
}

int	preparser(char **str)
{
	int		i;
	int		flag;
	char	*help;

	i = 0;
	flag = 0;
	if (!*str)
		return (1);
	while ((*str)[i])
	{
		if ((*str)[i] == '\'' || (*str)[i] == '"')
			flag = check_closed(*str, &i, (*str)[i]);
		i++;
	}
	if (!flag)
	{
		help = *str;
		*str = ft_strtrim(*str, "\t\n\v\f\r ");
		cleaning(&help);
	}
	return (flag);
}
