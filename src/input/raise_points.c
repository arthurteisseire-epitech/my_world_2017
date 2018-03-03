/*
** EPITECH PROJECT, 2017
** File Name : raise_points.c
** File description:
** by ozz
*/

#include "my_world.h"
#include "stats.h"
#include "map.h"
#include "toolbar.h"

void raise_tile(world_t *wd, sfVector2i pt)
{
	int raise = wd->stats->increasing ? -1 : 1;
	int force = wd->stats->force;

	raise *= force;
	wd->map->map_3d[pt.x][pt.y] += raise;
	if (pt.y + 1 < NB_ROW)
		wd->map->map_3d[pt.x][pt.y + 1] += raise;
	if (pt.x + 1 < NB_COL)
		wd->map->map_3d[pt.x + 1][pt.y] += raise;
	if (pt.x + 1 < NB_COL && pt.y + 1 < NB_COL)
		wd->map->map_3d[pt.x + 1][pt.y + 1] += raise;
}

void raise_radius(world_t *wd, sfVector2i pt, sfVector2i exp_tl)
{
	exp_tl.y = NB_ROW - 1;
	while (exp_tl.y > 0) {
		if (ABS(exp_tl.x - pt.x) + ABS(exp_tl.y - pt.y) < wd->stats->radius)
			raise_tile(wd, exp_tl);
		exp_tl.y--;
	}
}

void raise(world_t *wd, sfVector2i pt)
{
	sfVector2i expand_tile;

	expand_tile.x = NB_ROW - 1;
	if (wd->stats->raise_mode == 1) {
		while (expand_tile.x > 0) {
			raise_radius(wd, pt, expand_tile);
			expand_tile.x--;
		}
	} else 
		wd->map->map_3d[pt.x][pt.y] += wd->stats->increasing ? -1 : 1;
}
