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
	if (init_map_3d(wd) == -1)
		return (-1);
	wd->map->map_2d = create_map_2d(wd, wd->map->map_3d);
	if (wd->map->map_2d == NULL)
		return (-1);
	return (0);
}

int init_map_3d(world_t *wd)
{
	wd->map->map_3d = malloc(sizeof(int *) * wd->nb_row);
	if (wd->map->map_3d == NULL)
		return (-1);
	for (int y = 0; y < wd->nb_row; y++) {
		wd->map->map_3d[y] = malloc(sizeof(int) * wd->nb_col);
		if (wd->map->map_3d[y] == NULL)
			return (-1);
		for (int x = 0; x < wd->nb_col; x++)
			wd->map->map_3d[y][x] = 0;
	}
	return (0);
}

sfVector2f **create_map_2d(world_t *wd, int **map_3d)
{
	sfVector2f **map_2d = malloc(sizeof(sfVector2f *) * wd->nb_row);

	if (map_2d == NULL)
		return (NULL);
	for (int y = 0; y < wd->nb_row; y++) {
		map_2d[y] = malloc(sizeof(sfVector2f) * wd->nb_col);
		if (map_2d[y] == NULL)
			return (NULL);
		for (int x = 0; x < wd->nb_col; x++) {
			map_2d[y][x] = project_iso_point(
			wd->cam,
			x * wd->cam->scale.x + wd->cam->offset.x,
			y * wd->cam->scale.y + wd->cam->offset.y,
			map_3d[y][x] * wd->cam->scale.z);
		}
	}
	return (map_2d);
}
