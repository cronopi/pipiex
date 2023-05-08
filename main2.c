#include "ft_pipex.h"
#include <unistd.h>

void ft_pipex(char **args1, char **args2, char *infile, char *outfile, char **envp)
{
	int		fd[2];
	pid_t	pid;
	pid_t	pid2;
	 int file_desc;

	//char*	envp[] = { "PATH=/bin", NULL };

	if (pipe(fd) == -1)
	{
		perror("Error al crear la tubería");
		return ;
	}

	pid = fork();
	if (pid < 0)
	{
		perror("Error al crear el proceso padre-hijo\n");
		return ;
	}
	else if (pid == 0)
	{
		file_desc = open(infile, O_RDONLY);
		dup2(file_desc, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		//close(file_desc); los leaks solo tengo que verlos cuando tengo errores, cuando salgo eon execve no voy a tener leaks nunca
		execve("/bin/cat", args1, envp);
	}

	pid2 = fork();
	if (pid2 < 0)
	{
		perror("Error al crear el proceso padre-hijo\n");
		return ;
	}
	else if (pid2 == 0)
	{
		int file_desc = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dup2(fd[0], STDIN_FILENO);
		dup2(file_desc, STDOUT_FILENO);
		close(fd[1]);
		//close(file_desc);
		execve("/bin/grep", args2, envp);
	}

	close (fd[0]);
	close (fd[1]);
	waitpid(pid, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int main (int argc, char **argv, char **envp)
{
	if (argc == 5)
	{
		char *args1[] = {argv[2], NULL};
		char *args2[] = {argv[3], "man", NULL};
		ft_pipex(args1, args2, argv[1], argv[4], envp);
	}
	else
		write(1, "Error", 5);
	return (0);
}
