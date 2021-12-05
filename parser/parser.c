#include "libft.h"
#include <stdio.h>

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
	while (str[++*i] && str[*i] != '\'')
	before = ft_substr(str, 0, help);
	now = ft_substr(str, help + 1, *i - help - 1);
	now = slash_in_quotes(now);
	after = ft_strdup(str + *i + 1);
	free(str);
	str = ft_strjoin(before, now);
	free(before);
	free(now);
	now = ft_strjoin(str, after);
	free(str);
	free(after);
	*i = *i - 2;
	return (now);
}

char	*slash(char *str, int *i)
{
	char	*before;
	char	*after;

	before = ft_substr(str, 0, *i);
	after = ft_strdup(str + *i);
	free(str);
	str = ft_strjoin(before, after);
	free(before);
	free(after);
	return (str);
}

char	*double_quotes(char *str, int *i)
{

}

void	parser(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'')
			str = quotes(str, &i);
		if (str[i] == '\\')
			str = slash(str, &i);
		if (str[i] == '"')
			str = double_quotes(str, &i);
	}
	printf("%s\n", str);
}

int	main(void)
{
	char	*str;

	str = ft_strdup("Hello s\\'s world \\fdf\\\\\\df' nice morning    'jfklasjlkasjfsdao4uj4u845495'4394r84___  ' dsf");
	parser(str);
	return (0);
}
