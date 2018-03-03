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
