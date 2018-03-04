/*
** EPITECH PROJECT, 2017
** File Name : run.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "my_world.h"
#include "states.h"
#include "init.h"
#include "destroy.h"
#include "save.h"

int run(char *pathname)
{
	world_t wd;

	wd.nb_row = NB_ROW;
	wd.nb_col = NB_COL;
	if (pathname != NULL)
		wd.pathname = pathname;
	else
		wd.pathname = NULL;
	if (init_world(&wd) == -1)
		return (-1);
	while (sfRenderWindow_isOpen(wd.window)) {
		if (states(&wd) == -1)
			return (-1);
	}
	if (destroy(&wd) == -1)
		return (-1);
	return (0);
}
