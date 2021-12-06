#include "libft.h"
#include <stdio.h>

void	cleaning(char **data)
{
	free(*data);
	*data = NULL;
}

int	is_key(char c)
{
	return (c == '_' || ft_isalnum(c));
}

char	*slash_in_quotes(char *str)
{
	int		i;
	int		count;
	char	*res;

	i = -1;
	count = 0;
	while (str[++i])
		if (str[i] == '\\')
			count++;
	if (!count)
		return (str);
	res = (char *)malloc(ft_strlen(str) + count + 1);
	i = -1;
	count = 0;
	while (str[++i])
	{
		res[i + count] = str[i];
		if (str[i] == '\\')
			res[i + ++count] = '\\';
	}
	res[i + count] = '\0';
	free(str);
	return (res);
}

char	*quotes(char *str, int *i)
{
	int		help;
	char	*before;
	char	*now;
	char	*after;

	help = *i;
	(*i)++;
	while (str[*i] && str[*i] != '\'')
		(*i)++;
	before = ft_substr(str, 0, help);
	now = ft_substr(str, help + 1, *i - help - 1);
	now = slash_in_quotes(now);
	after = ft_strdup(str + *i + 1);
	cleaning(&str);
	str = ft_strjoin(before, now);
	cleaning(&before);
	cleaning(&now);
	now = ft_strjoin(str, after);
	cleaning(&str);
	cleaning(&after);
	*i = *i - 2;
	return (now);
}

char	*slash(char *str, int *i)
{
	char	*before;
	char	*after;

	before = ft_substr(str, 0, *i);
	after = ft_strdup(str + *i);
	cleaning(&str);
	str = ft_strjoin(before, after);
	cleaning(&before);
	cleaning(&after);
	return (str);
}

char	*double_quotes(char *str, int *i)
{
	int		help;
	char	*before;
	char	*now;
	char	*after;

	help = *i;
	(*i)++;
	while (str[*i] && str[*i] != '"')
	{
		if (str[*i] == '\\' && (str[*i + 1] == '"' || str[*i + 1] == '$'))
			str = slash(str, i);
		(*i)++;
	}
	before = ft_substr(str, 0, help);
	now = ft_substr(str, help + 1, *i - help - 1);
	after = ft_strdup(str + *i + 1);
	cleaning(&str);
	str = ft_strjoin(before, now);
	cleaning(&before);
	cleaning(&now);
	now = ft_strjoin(str, after);
	cleaning(&str);
	cleaning(&after);
	*i = *i - 2;
	return (now);
}

char	*dollar(char *str, int *i)
{
	int		help;
	char	*before;
	char	*env_key;
	char	*after;

	help = *i;
	(*i)++;
	while (str[*i] && is_key(str[*i]))
		(*i)++;
	if (*i == help + 1)
		return (str);
	before = ft_substr(str, 0, help);
	env_key = ft_substr(str, help + 1, *i - help - 1);
	after = ft_strdup(str + *i + 1);
	cleaning(&str);
	str = ft_strjoin(before, env_key);
	cleaning(&before);
	cleaning(&env_key);
	env_key = ft_strjoin(str, after);
	cleaning(&str);
	cleaning(&after);
	(*i)--;
	return (env_key);
}

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

	str = ft_strdup("He\"l\\$l\"o s\\'s world \\fdf\\\\\\df' nice morning $nice0;    'jfklasjlkasj\"fsdao4uj4u84\"5495'4394r84___  ' dsf");
	// str = ft_strdup("hi 'ret\\ards'!");
	parser(str);
	while(1);
	return (0);
}
