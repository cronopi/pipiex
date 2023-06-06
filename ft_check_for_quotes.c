#include "ft_pipex.h"

int	ft_check_for_quotes(char *cmd1)
{
	int	i;

	i = 0;
	while (cmd1[i])
	{
		if (cmd1[i] == '\'' || cmd1[i] == '\"')
			return (1);
		i++;
	}
	return (0);
}
