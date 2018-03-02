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
#include "toolbar.h"

#define RADIUS 15

int detect_point(world_t *wd, sfVector2i pt, sfVector2i pos)
{
	int map_x = wd->map->map_2d[pt.x][pt.y].x;
	int map_y = wd->map->map_2d[pt.x][pt.y].y;
	int mouse_x = pos.x;
	int mouse_y = pos.y;

	if (map_x - RADIUS < mouse_x && mouse_x < map_x + RADIUS) {
		if (map_y - RADIUS < mouse_y && mouse_y < map_y + RADIUS) {
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
	sfVector2i pt;
	pt.x = NB_ROW - (int)wd->toolbar->tile_mode;
	int (*collide)(world_t *, sfVector2i, sfVector2i);

	collide = wd->toolbar->tile_mode ? &detect_tile : &detect_point;
	while (pt.x > 0) {
		pt.x--;
		pt.y = NB_COL - (int)wd->toolbar->tile_mode;
		while (pt.y > 0) {
			pt.y--;
			if (collide(wd, pt, pos))
				return (1);
		}
	}
	return (0);
}
