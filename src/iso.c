/*
** EPITECH PROJECT, 2017
** File Name : iso.c
** File description:
** Ozz
*/
#include "my_world.h"

sfVector2f project_iso_point(int x, int y, int z)
{
	sfVector2f point_2d;

	point_2d.x = cos(ANGLE_X) * x - cos(ANGLE_X) * y;
	point_2d.y = sin(ANGLE_Y) * y + sin(ANGLE_Y) * x - z;
	return (point_2d);
}

sfVector2f **create_map_2d(int **map_3d)
{
	sfVector2f **map_2d = malloc(sizeof(sfVector2f *) * MAP_Y);

	for (int y = 0; y < MAP_Y; y++) {
		map_2d[y] = malloc(sizeof(sfVector2f) * MAP_X);
		for (int x = 0; x < MAP_X; x++) {
			map_2d[y][x] = project_iso_point(x, y, map_3d[y][x]);
		}
	}
	return (map_2d);
}

void draw_line(sfVector2f point_b, sfVector2f point_2)
{
	sfVertexArray *line;

	sfRenderWindow_drawVertexArray(window, line, NULL);
}

void draw_map_2d(sfRenderWindow *window)
{
	for (int y = 0; y < MAP_Y; y++) {
		for (int x = 0; x < MAP_X; x++) {
			draw_line
		}
	}
}
