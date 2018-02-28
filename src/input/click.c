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
#define RADIUS 15

void raise(world_t *wd, int x, int y)
{
	printf("RAISE X:%d Y:%d\n", x, y);
	wd->map_3d[x][y]--;
}

void f(world_t *wd, int x, int y, sfVector2i pos)
{
	int map_x = wd->map_2d[x][y].x;
	int map_y = wd->map_2d[x][y].y;
	int mouse_x = pos.x;
	int mouse_y = pos.y;
	
	//printf("MOUSE X:%d Y:%d\n", pos.x, pos.y);
	//printf("MAP X:%d Y:%d\n", map_x, map_y);
	if (map_x - RADIUS < mouse_x && mouse_x < map_x + RADIUS) {
		if (map_y - RADIUS < mouse_y && mouse_y < map_y + RADIUS) {
			raise(wd, x, y);
		}
	}
}

int check_map_2d(world_t *wd, sfVector2i pos)
{
	for (int x = 0; x < NB_COL; x++) {
		for (int y = 0; y < NB_ROW; y++) {
			f(wd, x, y, pos);
		}
	}
	return (0);
}
