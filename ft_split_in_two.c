#include "ft_pipex.h"

void	ft_quote_duplicate(char *cmd1, char **args, int j)
{
	int	i;
	int	k;
	int	l;

	i = 0;
	k = 0;
	l = 0;
	while (i < j + 1)
	{
		if (cmd1[i] == '\0')
		{
			if (l == 0)
				args[k] = ft_strdup(cmd1); // awk '{count++} END {print count}'
			else
				args[k] = ft_strdup(cmd1 + l);
			k++;
			l = i + 1;
		}
		i++;
	}
	args[k] = NULL;
}

char	**ft_quote_string(char *cmd1, int j)
{
	int	i;
	int	k;
	char **args;

	i = 0;
	k = 0;
	while (i < j)
	{
		if (cmd1[i] == '\'')
		{
			i++;
			while (cmd1[i] != '\'')
				i++;
		}
		if (cmd1[i] == '\"')
		{
			i++;
			while (cmd1[i] != '\"')
				i++;
		}
		if (cmd1[i] == ' ')
			cmd1[i] = '\0';
		k++;
		i++;
	}
	args = malloc(sizeof(char *) * (k + 1));
	return (args);
}

char **ft_split_in_two(char *cmd1)
{
	char **args;
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	j = ft_strlen(cmd1);
	if (ft_check_for_quotes(cmd1) == 0)
	{
		args = ft_split(cmd1, ' ');
		return (args);
	}
	args = ft_quote_string(cmd1, j);
	ft_quote_duplicate(cmd1, args, j);
	while (i < j)
	{
		if (cmd1[i] == '\0')
			cmd1[i] = ' ';
		i++;
	}
	/* 	while (++i < j)
		if (cmd1[i] == '\0')
			cmd1[i] = ' '; */

	while (args[k])
	{
		args[k] = ft_strtrim(args[k], "\'\"");
		k++;
	}
	return (args);
}
