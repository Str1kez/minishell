/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:34:57 by tnessrou          #+#    #+#             */
/*   Updated: 2021/12/10 18:12:34 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

char	*quotes(char *str, int *i);
char	*double_quotes(char *str, int *i);
// char	*slash_in_quotes(char *str);
char	*slash(char *str, int *i);
char	*dollar(char *str, int *i);
void	cleaning(char **data);

#endif