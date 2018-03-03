/*
** EPITECH PROJECT, 2017
** File Name : check_env.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my.h"

int len_tokens(char **tokens)
{
	int i = 0;

	while (tokens[i] != NULL)
		i++;
	return (i);
}

int check_env_var(char *env_var)
{
	int i = 0;
	char **key_value = split(env_var, "=");

	if (key_value == NULL)
		return (-1);
	if (my_strcmp(key_value[0], "DISPLAY") == 0) {
		if (len_tokens(key_value) == 1)
			return (-1);
		else
			return (1);
	}
	while (key_value[i] != NULL) {
		free(key_value[i]);
		i++;
	}
	free(key_value);
	return (0);
}

int check_env(char **env)
{
	int i = 0;
	int status;

	while (env[i] != NULL) {
		status = check_env_var(env[i]);
		if (status == -1)
			return (-1);
		else if (status == 1)
			return (0);
		i++;
	}
	return (-1);
}
