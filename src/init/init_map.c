/*
** EPITECH PROJECT, 2017
** File Name : init_map.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my_world.h"
#include "map.h"
#include "camera.h"
#include "init.h"

int init_map(world_t *wd)
{
	wd->map = malloc(sizeof(map_t));
	if (wd->map == NULL)
		return (-1);
	if (init_map_3d(wd->map) == -1)
		return (-1);
	wd->map->map_2d = create_map_2d(wd->cam, wd->map->map_3d);
	if (wd->map->map_2d == NULL)
		return (-1);
	return (0);
}

int init_map_3d(map_t *map)
{
	map->map_3d = malloc(sizeof(int *) * NB_ROW);
	if (map->map_3d == NULL)
		return (-1);
	for (int y = 0; y < NB_ROW; y++) {
		map->map_3d[y] = malloc(sizeof(int) * NB_COL);
		if (map->map_3d[y] == NULL)
			return (-1);
		for (int x = 0; x < NB_COL; x++)
			map->map_3d[y][x] = 0;
	}
	map->map_3d[0][0] = -6;
	return (0);
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
