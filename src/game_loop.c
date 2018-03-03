/*
** EPITECH PROJECT, 2017
** File Name : run.c
** File description:
** by Arthur Teisseire
*/

#include "my_world.h"
#include "states.h"
#include "init.h"
#include "destroy.h"

int run(void)
{
	world_t wd;
	sfTime time = {500};

	if (init_world(&wd) == -1)
		return (-1);
	while (sfRenderWindow_isOpen(wd.window)) {
		if (states(&wd, &time) == -1)
			return (-1);
	}
	if (destroy(&wd) == -1)
		return (-1);
	return (0);
}
