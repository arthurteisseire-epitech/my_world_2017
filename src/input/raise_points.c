/*
** EPITECH PROJECT, 2017
** File Name : raise_points.c
** File description:
** by ozz
*/

#include "my_world.h"
#include "toolbar.h"
#include "map.h"

void raise(world_t *wd, sfVector2i pt)
{
	int raise = wd->toolbar->increasing ? -1 : 1;

	wd->map->map_3d[pt.x][pt.y] += raise;
	if (wd->toolbar->tile_mode == 1) {
		if (pt.y + 1 < NB_ROW)
			wd->map->map_3d[pt.x][pt.y + 1] += raise;
		if (pt.x + 1 < NB_COL)
			wd->map->map_3d[pt.x + 1][pt.y] += raise;
		if (pt.x + 1 < NB_COL && pt.y + 1 < NB_COL)
			wd->map->map_3d[pt.x + 1][pt.y + 1] += raise;
	}
}

