/*
** EPITECH PROJECT, 2017
** File Name : iso.c
** File description:
** Ozz
*/

#include "my_world.h"
#include "screen.h"

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
			map_2d[y][x] = project_iso_point(
			x * SCALE_X, 
			y * SCALE_Y, 
			map_3d[y][x] * SCALE_Z);
		}
	}
	return (map_2d);
}

void draw_line(sfRenderWindow *window, sfVector2f point_a, sfVector2f point_b)
{
	sfVertexArray *line = sfVertexArray_create();
	sfVertex vertex_a = {.position = point_a, .color = sfWhite};
	sfVertex vertex_b = {.position = point_b, .color = sfWhite};

	sfVertexArray_append(line, vertex_a);
	sfVertexArray_append(line, vertex_b);
	sfVertexArray_setPrimitiveType(line, sfLinesStrip);
	sfRenderWindow_drawVertexArray(window, line, NULL);
}

void display_grid_point(screen_t *sc, int x, int y)
{
	if (x < MAP_X - 1)
		draw_line(sc->window, sc->map_2d[y][x], sc->map_2d[y][x + 1]);
	if (y < MAP_Y - 1)
		draw_line(sc->window, sc->map_2d[y][x], sc->map_2d[y + 1][x]);
}

void draw_map_2d(screen_t *sc)
{
	for (int y = 0; y < MAP_Y; y++) {
		for (int x = 0; x < MAP_X; x++) {
			display_grid_point(sc, x, y);
		}
	}
}
