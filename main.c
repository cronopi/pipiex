/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:14:13 by roberto           #+#    #+#             */
/*   Updated: 2023/05/02 14:38:11 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

//debe utilizar 4 argumentos,
// 2 archivos
// 2 comandos
// el programa debe recibir 2 comandos
// debo recoger el prinmer comando
// el comando de la izquierda del pipe(output) debe pasarse a la derecha del pipe(como imput) y realizar el comando con "ambos".
// tengo que abrir el archivo leerlo y antes de salir del programa cerrarlo

void ft_pipex()
{

}

int main (int argc, char **argv, char **envp) // ls -l
{
	if (argc == 1)
	{
		char	*test;
		char *args[] = {"ls", "-l", NULL};
		int		j;

		j = 0;
		while(envp[j])
		{
			test = ft_strnstr(envp[j], "PATH", 999);
			if (test != NULL)
				break ;
			j++;
		}
		execve("/bin/ls", args, envp);
		//ft_pipex();
	}
	else
		write(1, "Error", 5);
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
*/
