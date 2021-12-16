/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:43:36 by tnessrou          #+#    #+#             */
/*   Updated: 2021/12/16 21:34:41 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	row_data_manipulating(char **str, t_env *env_list, t_saver **save)
{
	int		i;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == '\'')
			(*str) = quotes((*str), &i);
		if ((*str)[i] == '\\')
			(*str) = slash((*str), &i);
		if ((*str)[i] == '"')
			(*str) = double_quotes((*str), &i, env_list);
		if ((*str)[i] == '$')
			(*str) = dollar((*str), &i, env_list);
		if ((*str) && !(*save)->available && \
		(is_space((*str)[i + 1]) || (*str)[i + 1] == 0 || \
		(is_service((*str)[i + 1]) && (*str)[i + 1] != '\'' && \
		(*str)[i + 1] != '"')))
			saver_fill((*str), i, *save);
		i++;
	}
	printf("%s\n", (*str));
	printf("%s\n", (*save)->line);
}

int	commands_parsing(char *str, t_saver *save, t_cmd **cmd, t_cmd **new)
{
	// TODO: создать список с командами
}

void	parser(char *str, t_env *env_list)
{
	t_saver	*save;

	save = init_saver();
	if (!str)
		print_error("Error in line");
	row_data_manipulating(&str, env_list, &save);
	if (!str)
		print_error("Error in line after parsing");
	// * здесь парсинг команд
	cleaning(&str);
	clean_saver(&save);
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
	// str = ft_strdup("'ksjfkls '\" jdskajfjdfk\"");
	str = ft_strdup("yeah, tha\"t' $USER is' \"- me             ");
	// ! Не проверять парсер с гнлом, так как в процессе парсера удаляется значение
	// fd = open("../parser/test.txt", O_RDONLY);
	// while (get_next_line(fd, &str))
		// parser(str, env_list);
	if (preparser(&str))
		print_error("Error in preparsing stage");
	printf("%lu\n", ft_strlen(str));
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
