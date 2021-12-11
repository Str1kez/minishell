/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:41:47 by tnessrou          #+#    #+#             */
/*   Updated: 2021/12/11 17:42:34 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	s_1;
	unsigned char	s_2;

	s_1 = *s1;
	s_2 = *s2;

	while (s_1 == s_2 && s_1 && s_2)
	{
		s_1 = *++s1;
		s_2 = *++s2;
	}
	return (s_1 - s_2);
}
