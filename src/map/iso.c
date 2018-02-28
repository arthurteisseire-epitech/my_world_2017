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
	sfVector2f **map_2d = malloc(sizeof(sfVector2f *) * NB_ROW);

	if (map_2d == NULL)
		return (NULL);
	for (int y = 0; y < NB_ROW; y++) {
		map_2d[y] = malloc(sizeof(sfVector2f) * NB_COL);
		if (map_2d[y] == NULL)
			return (NULL);
		for (int x = 0; x < NB_COL; x++) {
			map_2d[y][x] = project_iso_point(
			cam,
			x * cam->scale.x + cam->offset.x, 
			y * cam->scale.y + cam->offset.y, 
			map_3d[y][x] * cam->scale.z);
		}
	}
	return (map_2d);
}

int draw_shape(world_t *wd, sfVector2f *square_pos)
{
	sfConvexShape *shape = sfConvexShape_create();
	sfTexture *texture;
	
	if (shape == NULL)
		return (-1);
	texture = sfTexture_createFromFile("assets/bsd.png", NULL);
	if (texture == NULL)
		return (-1);
	sfConvexShape_setPointCount(shape, 4);
	for (int i = 0; i < 4; i++)
		sfConvexShape_setPoint(shape, i, square_pos[i]);
	sfConvexShape_setTexture(shape, texture, sfTrue);
	sfConvexShape_setOutlineThickness(shape, 2.0);
	sfConvexShape_setOutlineColor(shape, sfBlack);
	sfRenderWindow_drawConvexShape(wd->window, shape, NULL);
	free(shape);
	return (0);
}

int display_shape(world_t *wd, int x, int y)
{
	sfVector2f square_pos[4] = {
		wd->map_2d[y][x],
		wd->map_2d[y][x + 1],
		wd->map_2d[y + 1][x + 1],
		wd->map_2d[y + 1][x],
	};

	if (draw_shape(wd, square_pos) == -1)
		return (-1);
	return (0);
}

void draw_map_2d(world_t *wd)
{
	for (int y = 0; y < NB_ROW - 1; y++) {
		for (int x = 0; x < NB_COL - 1; x++) {
			display_shape(wd, x, y);
		}
	}
}
