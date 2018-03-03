/*
** EPITECH PROJECT, 2017
** File Name : disp_stats.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "my_world.h"
#include "toolbar.h"

char *stats_to_str(world_t *wd)
{
	char *str = NULL;

	my_realloc(str, "Mode: ", 6);
	if (wd->toolbar->raise_mode == 1)
		my_realloc(str, "Tile\n", 5);
	if (wd->toolbar->raise_mode == 1)
		my_realloc(str, "Corner\n", 7);
	my_realloc(str, "Radius: ", 8);
	my_realloc(str, my_itoa(wd->toolbar->radius), 
			nb_len(wd->toolbar->radius));
	my_realloc(str, "\n: Force: ", 10);
	my_realloc(str, my_itoa(wd->toolbar->force),
			nb_len(wd->toolbar->force));
	return (str);
}

void disp_stats(world_t *wd, char *stat_str)
{
}
