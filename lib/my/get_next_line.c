/*
** EPITECH PROJECT, 2017
** File Name : get_next_line.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char buffer[READ_SIZE];
	static char *begin = buffer;
	char *line = NULL;
	int index;
	int size;

	if ((index = find_backspace(begin)) != -1)
		return (cut_line(&begin, line, index));
	line = my_realloc(line, begin, my_strlen(begin));
	while ((size = read(fd, buffer, READ_SIZE)) > 0) {
		buffer[size] = '\0';
		begin = buffer;
		if ((index = find_backspace(begin)) != -1)
			return (cut_line(&begin, line, index));
		else if (size < READ_SIZE)
			return (cut_line(&begin, line, size));
		line = my_realloc(line, begin, my_strlen(begin));
	}
	free(line);
	return (NULL);
}

char *cut_line(char **begin, char *line, int index_bn)
{
	char *res = malloc(1);

	if (res == NULL)
		return (NULL);
	*res = 0;
	line = my_realloc(line, *begin, index_bn);
	res = my_realloc(res, line, my_strlen(line));
	*begin += index_bn + 1;
	free(line);
	return (res);
}

char *my_realloc(char *dest, char *src, int len_src)
{
	int len_dest = my_strlen(dest);
	char *res = malloc(sizeof(char) * (len_dest + len_src + 1));
	int i = 0;

	if (res == NULL)
		return (NULL);
	if (dest != NULL) {
		while (dest[i] != '\0') {
			res[i] = dest[i];
			i++;
		}
		free(dest);
	}
	i = 0;
	while (i < len_src) {
		res[len_dest + i] = src[i];
		i++;
	}
	res[len_dest + i] = '\0';
	return (res);
}

int find_backspace(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int my_strlen(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}
