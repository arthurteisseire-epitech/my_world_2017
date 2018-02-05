/*
** EPITECH PROJECT, 2017
** File Name : iso.c
** File description:
** Ozz
*/

#include <stdlib.h>
#include <math.h>
#include "my_world.h"
#include "camera.h"

sfVector2f project_iso_point(camera_t *cam, int x, int y, int z)
{
	sfVector2f point_2d;

	point_2d.x = cos(cam->angle.x) * x - cos(cam->angle.x) * y;
	point_2d.y = -(sin(cam->angle.y) * y + sin(cam->angle.y) * x - z);
	return (point_2d);
}

sfVector2f **create_map_2d(camera_t *cam, int **map_3d)
{
	sfVector2f **map_2d = malloc(sizeof(sfVector2f *) * MAP_Y);

	for (int y = 0; y < MAP_Y; y++) {
		map_2d[y] = malloc(sizeof(sfVector2f) * MAP_X);
		for (int x = 0; x < MAP_X; x++) {
			map_2d[y][x] = project_iso_point(
			cam,
			x * cam->scale.x + cam->offset.x, 
			y * cam->scale.y + cam->offset.y, 
			map_3d[y][x] * cam->scale.z);
		}
	}
	return (map_2d);
}

void draw_line(world_t *wd, sfVector2f point_a, sfVector2f point_b)
{
	sfVertexArray *line = sfVertexArray_create();
	sfVertex vertex_a = {.position = point_a, .color = sfWhite};
	sfVertex vertex_b = {.position = point_b, .color = sfWhite};

	sfVertexArray_append(line, vertex_a);
	sfVertexArray_append(line, vertex_b);
	sfVertexArray_setPrimitiveType(line, sfLinesStrip);
	sfRenderWindow_drawVertexArray(wd->window, line, NULL);
}

void display_grid_point(world_t *wd, int x, int y)
{
	if (x < MAP_X - 1)
		draw_line(wd, wd->map_2d[y][x], wd->map_2d[y][x + 1]);
	if (y < MAP_Y - 1)
		draw_line(wd, wd->map_2d[y][x], wd->map_2d[y + 1][x]);
}

void draw_map_2d(world_t *wd)
{
	for (int y = 0; y < MAP_Y; y++) {
		for (int x = 0; x < MAP_X; x++) {
			display_grid_point(wd, x, y);
		}
	}
}
