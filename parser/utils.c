/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:53:50 by tnessrou          #+#    #+#             */
/*   Updated: 2021/12/13 21:02:12 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// ? Надо ли вообще заводить ее?
void	cleaning(char **data)
{
	free(*data);
	*data = NULL;
}

void	print_error(const char *str)
{
	printf("%s\n", str);
	exit(1);
}
