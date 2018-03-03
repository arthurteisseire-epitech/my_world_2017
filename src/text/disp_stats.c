/*
** EPITECH PROJECT, 2017
** File Name : disp_stats.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my.h"
#include "my_world.h"
#include "toolbar.h"
#include "text.h"
#include "stats.h"

int stats_to_str(world_t *wd)
{
	char *radius = my_itoa(wd->stats->radius);
	char *force = my_itoa(wd->stats->force);

	if (radius == NULL || force == NULL)
		return (-1);
	my_strcpy(wd->stats->text->str, "Precision: ");
	if (wd->stats->raise_mode == 1)
		my_strcat(wd->stats->text->str, "Tile");
	else
		my_strcat(wd->stats->text->str, "Corner");
	my_strcat(wd->stats->text->str, "\nRadius: ");
	my_strcat(wd->stats->text->str, radius);
	my_strcat(wd->stats->text->str, "\nForce: ");
	my_strcat(wd->stats->text->str, force);
	sfText_setString(wd->stats->text->text, wd->stats->text->str);
	free(radius);
	free(force);
	return (0);
}
