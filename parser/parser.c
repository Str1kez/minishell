/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:43:36 by tnessrou          #+#    #+#             */
/*   Updated: 2021/12/11 18:02:31 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parser(char *str, t_env *env_list)
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
			str = double_quotes(str, &i, env_list);
		if (str[i] == '$')
			str = dollar(str, &i, env_list);
		i++;
	}
	printf("%s\n", str);
	cleaning(&str);
}

int	main(int argc, char **argv, char **envp)
{
	char	*str;
	int		fd;
	t_env	*env_list;
	t_env	*lol;

	(void) argc;
	(void) argv;
	env_list = init_env(envp);
	printf("%p\n", env_list);
	fd = open("test.txt", O_RDONLY);
	while (get_next_line(fd, &str))
		parser(str, env_list);
	printf("%p\n", env_list);
	lol = env_list;
	while (lol)
	{
		printf("%s=%s    %p\n", lol->key, lol->value, lol);
		lol = lol->next;
	}
	clean_env(&env_list);
	// ! Ошибка в очистке списка env
	// while (1);
	return (0);
}
