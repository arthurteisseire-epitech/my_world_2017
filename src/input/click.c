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
/*
int is_mouse_in_tile(world_t *wd, sfVector2i pos)
{
	return (0);
}
*/
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

int check_map_2d(world_t *wd, sfVector2i pos)
{
	sfVector2i pt;
	pt.x = NB_ROW;

	while (pt.x > 0) {
		pt.x--;
		pt.y = NB_COL;
		while (pt.y > 0) {
			pt.y--;
			if (detect_point(wd, pt, pos))
				return (1);
		}
	}
	return (0);
}
