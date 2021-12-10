/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:43:36 by tnessrou          #+#    #+#             */
/*   Updated: 2021/12/10 19:35:10 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

void	parser(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			str = quotes(str, &i);
		if (str[i] == '\\')
			str = slash(str, &i);
		if (str[i] == '"')
			str = double_quotes(str, &i);
		if (str[i] == '$')
			str = dollar(str, &i);
		i++;
	}
	printf("%s\n", str);
	cleaning(&str);
}

int	main(void)
{
	char	*str;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	while (get_next_line(fd, &str))
		parser(str);
	// while (1);
	return (0);
}
