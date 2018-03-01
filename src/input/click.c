/*
** EPITECH PROJECT, 2017
** File Name : click.c
** File description:
** Ozz
*/

#include"my_world.h"
#include"input.h"
#include"camera.h"
#include<stdio.h>
#include<stdlib.h>
#define RADIUS 15

typedef struct {
	sfVector2i top;
	sfVector2i bottom;
	sfVector2i left;
	sfVector2i right;
} tile_t;

int is_mouse_in_tile(world_t wd, sfVector2i pos)
{
	return (0);
}

void raise(world_t *wd, sfVector2i *pts, int nb_pt)
{
	//printf("RAISE X:%d Y:%d\n", x, y);
	for (int i = 0; i < nb_pt; i++) {

		wd->map_3d[pts[i].x][pts[i].y]--;
	}
}

void detect_point(world_t *wd, sfVector2i pt, sfVector2i pos)
{
	int map_x = wd->map_2d[pt.x][pt.y].x;
	int map_y = wd->map_2d[pt.x][pt.y].y;
	int mouse_x = pos.x;
	int mouse_y = pos.y;
	sfVector2i *pts = point_to_tile(pt);

	pts[0] = pt;
	//printf("MOUSE X:%d Y:%d\n", pos.x, pos.y);
	//printf("MAP X:%d Y:%d\n", map_x, map_y);
	if (map_x - RADIUS < mouse_x && mouse_x < map_x + RADIUS) {
		if (map_y - RADIUS < mouse_y && mouse_y < map_y + RADIUS) {
			raise(wd, pts, 1);
		}
	}
}

int check_map_2d(world_t *wd, sfVector2i pos)
{
	sfVector2i pt;
	pt.x = NB_COL;

	while (pt.x > 0) {
		pt.x--;
		pt.y = NB_ROW;
		while (pt.y > 0) {
			pt.y--;
			detect_point(wd, pt, pos);
		}
	}
	return (0);
}
