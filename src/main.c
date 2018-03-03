/*
** EPITECH PROJECT, 2017
** File Name : main.c
** File description:
** By Arthur Teisseire
*/

#include <stdlib.h>
#include "my.h"
#include "my_world.h"
#include "states.h"
#include "init.h"

static int len_tokens(char **tokens)
{
	int i = 0;

	while (tokens[i] != NULL)
		i++;
	return (i);
}

static int check_env_var(char *env_var)
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

static int check_env(char **env)
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

int main(int ac, char **av, char **env)
{
	if (ac != 1) {
		my_puterror(av[0]);
		my_puterror(": Must take exactly one argument\n");
		return (84);
	}
	if (check_env(env) == -1) {
		my_puterror("Error with the DISPLAY environment variable\n");
		return (84);
	}
	return (run());
}
