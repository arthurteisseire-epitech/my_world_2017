/*
** EPITECH PROJECT, 2017
** File Name : main.c
** File description:
** By Arthur Teisseire
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "my_world.h"
#include "states.h"
#include "init.h"
#include "save.h"

static int print_full_file(char *pathname)
{
	int fd = open(pathname, O_RDONLY);
	char buffer[4096];
	int size;

	if (fd == -1)
		return (-1);
	while ((size = read(fd, buffer, 4096))) {
		buffer[size] = '\0';
		my_putstr(buffer);
	}
	return (0);
}

static int check_args(int ac, char **av)
{
	int status;

	if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
		print_full_file("readme");
		return (0);
	}
	if (ac == 1) {
		status = run(NULL);
		if (status == -1)
			print_full_file("readme");
		return (status);
	} else if (ac == 2) {
		status = run(av[1]);
		if (status == -1)
			print_full_file("readme");
		return (status);
	}
	return (1);
}

int main(int ac, char **av, char **env)
{
	int status = check_args(ac, av);

	if (status != 1)
		return (status);
	if (check_env(env) == -1) {
		my_puterror("Error with the DISPLAY environment variable\n");
		return (84);
	}
	my_puterror(av[0]);
	my_puterror(": Invalid number of arguments\n");
	return (84);
}
