/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazurmen <nazurmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:54:31 by rcastano          #+#    #+#             */
/*   Updated: 2023/02/20 17: by nazurmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clean_up(char **clean)
{
	if (*clean)
	{
		free(*clean);
		*clean = 0;
	}
}

static char	*get_line(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
			return (&buf[i + 1]);
		i++;
	}
	return (NULL);
}

int	aux_funtion(char **aux, char **str, char *buf)
{
	char	*check;
	char	*free_aux;

	*str = ft_strjoin_mod(*str, *aux);
	check = get_line(*aux);
	if (check != NULL)
	{
		free_aux = *aux;
		*aux = 0;
		*aux = ft_strdup(check);
		clean_up(&free_aux);
		if ((*aux) != 0 && (*aux)[0] == '\0')
			clean_up(aux);
		free(buf);
		return (1);
	}
	return (0);
}

int	bucle(char **buf, char **aux, char **str, int i)
{
	char	*check;

	if (*aux != 0)
		clean_up(aux);
	if (i == -1)
	{
		if (*str != 0)
			free(*str);
		free(*buf);
		return (1);
	}
	(*buf)[i] = '\0';
	check = get_line(*buf);
	if (check != NULL && BUFFER_SIZE != 1)
		*aux = ft_substr(check, 0, i - (check - *buf));
	*str = ft_strjoin_mod(*str, *buf);
	if (check != NULL)
	{
		if ((*aux) != 0 && (*aux)[0] == '\0')
			clean_up(aux);
		free(*buf);
		return (2);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*aux;
	int			i;
	char		*buf;

	str = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	if (aux != 0 && aux_funtion(&aux, &str, buf) == 1)
		return (str);
	i = read(fd, buf, BUFFER_SIZE);
	while (i != 0)
	{
		i = bucle(&buf, &aux, &str, i);
		if (i == 1)
			return (NULL);
		else if (i == 2)
			return (str);
		i = read(fd, buf, BUFFER_SIZE);
	}
	clean_up(&aux);
	return (free(buf), str);
}

/* int	main(void)
{
	int		fd;
	//int		fd2;
	char	*str;

	fd = open("multiple_nlx5", O_RDONLY);
	//fd2 = open("filename.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("esto es el main:%s\n", str);
	free(str);
 	str = get_next_line(fd);
	printf("esto es el main:%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("esto es el main:%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("esto es el main:%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("esto es el main:%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("esto es el main:%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("esto es el main:%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("esto es el main:%s\n", str);
	free(str);
	close(fd);
	//close(fd2);
	//system("leaks a.out");

	return (0);
} */

/* 			free_aux = aux;
			aux = 0;
				aux = ft_strdup(check);
			clean_up(&free_aux);
			if (aux != 0 && aux[0] == '\0')
				clean_up(&aux);
			free(buf);
			return (str); */

/*
open("multiple_nlx5", O_RDONLY);

read(int fd, void *buf, size_t nbyte);
el nbyte hace referencia al número de bytes(chars o posiciones)
que va a avanzar/leer(copiar al buffer). el buffer es un bloque
de memoria, buffer debe tener un tamaño de memoria asignado con anterioridad.

Open lo hace es hacer accesible para el programa el archivo.
con fd estamos crando una forma de identificar/describir el archivo

Al hacer open he creado un puntero a la primera posicion
(de la letra del archivo)/del archivo.

//aux = ft_substr(buf, check - buf, i);


if (!buf = malloc(BUFFER_SIZE + 1));
		return (NULL);
*/
