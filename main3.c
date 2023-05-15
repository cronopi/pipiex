/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:14:13 by roberto           #+#    #+#             */
/*   Updated: 2023/05/11 18:39:17 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include "libft/libft.h"

void	ft_pipex(char *cmd1, char *cmd2, char **envp, char *infile, char *outfile)
{
	int		fd[2];
	pid_t	pid;
	pid_t	pid2;
	int		file_desc;
	char	**paths;
	char	**paths2;
	char	*path;
	char	*cmd;
	char	**args;
	char	**args2;
	int		j;
	int		i;
	int		test;

	j = 0;
	while(envp[j])
	{
		if (ft_strncmp(envp[j], "PATH=", 5) == 0)
		{
			path = ft_strdup(envp[j] + 5);
			break;
		}
		j++;
	}

	paths = ft_split(path, ':');
	args = ft_split(cmd1, ' ');
	j = 0;
	while (paths[j] != NULL)
	{
		cmd = ft_strjoin("/", args[0]);
		paths[j] = ft_strjoin(paths[j], cmd);
		if (access(paths[j], F_OK) == 0)
			break;
		//printf("esto que imprime %s\n", paths[j]);
		j++;
	}

	paths2 = ft_split(path, ':');
	args2 = ft_split(cmd2, ' ');
	i = 0;
	while (paths2[i] != NULL)
	{
		cmd2 = ft_strjoin("/", args2[0]);
		paths2[i] = ft_strjoin(paths2[i], cmd2);
		if (access(paths2[i], F_OK) == 0)
			break;
		//printf("y lo otro que imprime %s\n", paths[j]);
		i++;
	}

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
		execve(paths[j], args, envp);
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
		execve(paths2[i], args2, envp);
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
		ft_pipex(argv[2], argv[3], envp, argv[1], argv[4]);
	}
	else
		write(1, "error\n", 6);
	return (0);
}

/* int main (int argc, char **argv, char **envp)
{
	int		j;
	char	*test;

	j = 0;
	while(envp[j])
	{
		test = ft_strnstr(envp[j], "PATH", 999);
		if (test != NULL)
			break ;
		j++;
	}
	printf("esto es:%s\n", test);
	return (0);
} */

/* 	av[1] = infile
	av[2] = grep manzana
	av[3] = wc -w
	av[4] = outfile */

	/*
		FILE *fd = fopen("test.txt", "r");
		if (fd == NULL) {
			perror("se ha encontrado un error:");
			return errno;
	*/

	/*
		FILE *file = fopen("no_existe.txt", "r");
		if (file == NULL) {
			int errnum = errno;
			printf("Error al abrir el archivo: %s\n", strerror(errnum));
		}
	*/

	/*
	access() es una función que se utiliza para comprobar si un archivo se puede acceder o no,
	y si se puede acceder, comprobar el tipo de acceso que se tiene.

	access(primer argumento, segundo argumento)" toma dos argumentos:
	el primer argumento es una cadena que especifica la ruta del archivo
	el segundo argumento es un número que indica el tipo de acceso que se quiere comprobar.
	F_OK: para comprobar si el archivo o directorio existe.
	R_OK: para comprobar si se tiene permiso de lectura sobre el archivo o directorio.
	W_OK: para comprobar si se tiene permiso de escritura sobre el archivo o directorio.
	X_OK: para comprobar si se tiene permiso de ejecución sobre el archivo o directorio.
	La función "access()" Si el valor devuelto es 0, significa que el acceso es posible; de lo contrario, devuelve -1.

	int resultado = access("archivo.txt", R_OK);
	if (resultado == 0) {
		printf("Se puede acceder al archivo de texto.\n");
	} else {
		printf("No se puede acceder al archivo de texto.\n");
	}
	*/

	/*
	dup()
	// open() returns a file descriptor file_desc to a
	// the file "dup.txt" here"

	int file_desc = open("dup.txt", O_WRONLY | O_APPEND);

	if(file_desc < 0)
		printf("Error opening the file\n");

	// dup() will create the copy of file_desc as the copy_desc
	// then both can be used interchangeably.

	int copy_desc = dup(file_desc);

	// write() will write the given string into the file
	// referred by the file descriptors

	write(copy_desc,"This will be output to the file named dup.txt\n", 46);

	write(file_desc,"This will also be output to the file named dup.txt\n", 51);
	*/

	/*
	dup2()
	int file_desc = open("tricky.txt",O_WRONLY | O_APPEND);

	// here the newfd is the file descriptor of stdout (i.e. 1)
	dup2(file_desc, 1) ;

	// All the printf statements will be written in the file
	// "tricky.txt"
	printf("I will be printed in the file tricky.txt\n");
	*/

	/*
	execve(argumento1, argumento2, argumento3)
	 char *args[] = {"ls", "-l", NULL};
	execve("ls", args, envp);
	perror("execve failed");
	return 0;
	*/

	/*
		pid_t pid;

	pid = fork();

	if (pid == 0) {
		// Este es el proceso hijo
		printf("Soy el proceso hijo\n");
	} else if (pid > 0) {
		// Este es el proceso padre
		printf("Soy el proceso padre\n");
	} else {
		// La creación del proceso hijo falló
		printf("Error al crear el proceso hijo\n");
	}
	Si "fork()" devuelve 0, significa que se está ejecutando en el proceso hijo,por lo que se imprime "Soy el proceso hijo".
	Si "fork()" devuelve un número positivo, significa que se está ejecutando en el proceso padre, por lo que se imprime "Soy el proceso padre".
	Si "fork()" devuelve un número negativo, significa que la creación del proceso hijo falló, por lo que se imprime "Error al crear el proceso hijo".
	*/

	/*
		La función unlink() en C se utiliza para eliminar un archivo del sistema de archivos.
		int main()
		{
		char* filename = "archivo.txt";
		int result = unlink(filename);
		if (result == 0) {
			printf("El archivo %s fue eliminado exitosamente.\n", filename);
		} else {
			perror("Error al eliminar el archivo");
			exit(EXIT_FAILURE);
		}
		return 0;
}
	*/



/*
int main()
{
	int fd[2];
	char buffer[30];
	pid_t pid;

	// Crear la tubería
	if (pipe(fd) == -1) {
		perror("Error al crear la tubería");
		return 1;
	}

	// Crear el proceso hijo
	pid = fork();

	if (pid < 0) {
		perror("Error al crear el proceso hijo");
		return 1;
	}

	if (pid == 0)
	{
		// Proceso hijo - lee desde la tubería
		close(fd[1]); // Cerrar extremo de escritura
		read(fd[0], buffer, 30);
		printf("Mensaje recibido: %s\n", buffer);
		close(fd[0]); // Cerrar extremo de lectura
	}
	else
	{
		// Proceso padre - escribe en la tubería
		wait(&status);
		close(fd[0]); // Cerrar extremo de lectura
		write(fd[1], "Hola mundo", 11);
		close(fd[1]); // Cerrar extremo de escritura
	}

	return 0;
}
______________________________________________________


Para extraer las diferentes rutas del PATH de la variable envp, puedes seguir los siguientes pasos:

Inicializa un contador i en 0.
Usa un bucle while para recorrer todos los elementos de envp.
Para cada elemento de envp, comprueba si comienza con la cadena "PATH=" utilizando la función ft_strncmp. Si es así, has encontrado la variable PATH y puedes salir del bucle.
Si el elemento no comienza con "PATH=", incrementa el contador i y continúa el bucle.
Si has encontrado la variable PATH, extrae su valor eliminando los primeros cinco caracteres de la cadena (que corresponden a "PATH=").
Utiliza la función ft_split para dividir la cadena de rutas del PATH en un arreglo de cadenas utilizando el carácter de dos puntos (:) como separador.
Aquí está el código para realizar estos pasos:

c
Copy code
int		main(int argc, char **argv, char **envp)
{
	if (argc == 1)
	{
		int		i;
		char	*path;
		char	**paths;

		i = 0;
		while (envp[i] != NULL)
		{
			if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			{
				path = ft_strdup(envp[i] + 5);
				break;
			}
			i++;
		}
		if (envp[i] == NULL)
			return (-1); // Si no se encuentra la variable PATH, terminamos la ejecución.

		paths = ft_split(path, ':');

		// Ahora puedes recorrer el arreglo `paths` para trabajar con cada ruta del `PATH`.
		// Recuerda liberar la memoria cuando hayas terminado de trabajar con cada variable.

		free(path);
		ft_free_split(paths); // Libera la memoria del arreglo `paths`.
	}
	else
		write(1, "Error", 5);
	return (0);
*/
