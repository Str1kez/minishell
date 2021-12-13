/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:43:36 by tnessrou          #+#    #+#             */
/*   Updated: 2021/12/13 21:51:52 by tnessrou         ###   ########.fr       */
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
	t_env	*env_list;
	// t_env	*lol;
	// int		fd;

	(void) argc;
	(void) argv;
	env_list = init_env(envp);
	// str = ft_strdup("ok, 'that is \"double quotes in single\" haha', fjkdjfkdf");
	// str = ft_strdup("ksjfkls $ jdskajfjdfk");
	str = ft_strdup("yeah, that $USER is - me");
	// ! Не проверять парсер с гнлом, так как в процессе парсера удаляется значение
	// fd = open("../parser/test.txt", O_RDONLY);
	// while (get_next_line(fd, &str))
		// parser(str, env_list);
	if (preparser(str))
		print_error("Error in sequence of quotes");
	parser(str, env_list);
	// lol = env_list;
	// while (lol)
	// {
	// 	printf("%s=%s\n", lol->key, lol->value);
	// 	lol = lol->next;
	// }
	clean_env(&env_list);
	// while (1);
	return (0);
}
