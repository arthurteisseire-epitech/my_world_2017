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

int run(char *pathname, int ac)
{
	world_t wd;
	sfTime time = {500};

	wd.nb_row = NB_ROW;
	wd.nb_col = NB_COL;
	wd.pathname = pathname;
	if (init_world(&wd, ac) == -1)
		return (-1);
	while (sfRenderWindow_isOpen(wd.window)) {
		if (states(&wd, &time) == -1)
			return (-1);
	}
	if (pathname != NULL && ac == 2)
		save_map(&wd);
	if (destroy(&wd) == -1)
		return (-1);
	return (0);
}
