/*
** EPITECH PROJECT, 2017
** File Name : run.c
** File description:
** by Arthur Teisseire
*/

#include "my_world.h"
#include "states.h"
#include "init.h"

int run(void)
{
	world_t wd;

	if (init_world(&wd) == -1)
		return (-1);
	while (sfRenderWindow_isOpen(wd.window)) {
		if (event(&wd) == -1)
			return (-1);
		if (update(&wd) == -1)
			return (-1);
		if (draw(&wd) == -1)
			return (-1);
	}
	if (destroy(&wd) == -1)
		return (-1);
	return (0);
}
