/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saver.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 21:03:32 by tnessrou          #+#    #+#             */
/*   Updated: 2021/12/16 21:04:14 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_saver	*init_saver(void)
{
	t_saver	*res;

	res = (t_saver *)malloc(sizeof(t_saver));
	res->line = NULL;
	res->available = 0;
	return (res);
}

void	saver_fill(char *str, int i, t_saver *save)
{
	save->line = ft_substr(str, 0, i + 1);
	save->available = 1;
}

void	clean_saver(t_saver **save)
{
	free((*save)->line);
	free(*save);
	*save = NULL;
}
