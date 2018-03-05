/*
** EPITECH PROJECT, 2017
** File Name : click.c
** File description:
** Ozz
*/

#include "my_world.h"
#include "input.h"
#include "camera.h"
#include "map.h"
#include "stats.h"

int detect_point(world_t *wd, sfVector2i pt, sfVector2i pos)
{
	int map_x = wd->map->map_2d[pt.x][pt.y].x;
	int map_y = wd->map->map_2d[pt.x][pt.y].y;
	int mouse_x = pos.x;
	int mouse_y = pos.y;

	if (map_x - HIT_BOX < mouse_x && mouse_x < map_x + HIT_BOX) {
		if (map_y - HIT_BOX < mouse_y && mouse_y < map_y + HIT_BOX) {
			raise(wd, pt);
			return (1);
		}
	}
	return (0);
}

int detect_tile(world_t *wd, sfVector2i pt, sfVector2i pos)
{
	if (tile_collide(wd, pt, pos)) {
		raise(wd, pt);
		return (1);
	}
	return (0);
}

int check_map_2d(world_t *wd, sfVector2i pos)
{
	sfVector2i pt = {
		wd->nb_row - wd->stats->raise_mode,
		wd->nb_col - wd->stats->raise_mode
	};

	while (pt.x > 0) {
		pt.x--;
		if (check_row(wd, pos, pt) == 1)
			return (1);
	}
	return (0);
}

int check_row(world_t *wd, sfVector2i pos, sfVector2i pt)
{
	int (*collide)(world_t *, sfVector2i, sfVector2i);

	collide = wd->stats->raise_mode ? &detect_tile : &detect_point;
	while (pt.y > 0) {
		pt.y--;
		if (collide(wd, pt, pos))
			return (1);
	}
	return (0);
}
