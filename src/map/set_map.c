/*
** EPITECH PROJECT, 2017
** File Name : convex.c
** File description:
** by Arthur Teisseire
*/

#include "my_world.h"
#include "map.h"
#include "camera.h"

int set_map_2d(world_t *wd, int **map_3d)
{
	for (int y = 0; y < NB_ROW; y++) {
		for (int x = 0; x < NB_COL; x++) {
			wd->map->map_2d[y][x] = project_iso_point(
			wd->cam,
			x * wd->cam->scale.x + wd->cam->offset.x, 
			y * wd->cam->scale.y + wd->cam->offset.y, 
			map_3d[y][x] * wd->cam->scale.z);
		}
	}
	return (0);
}

int set_tiles_from_2d(map_t *map)
{
	for (int y = 0; y < NB_ROW - 1; y++)
		for (int x = 0; x < NB_COL - 1; x++)
			set_shape(map, x, y);
	return (0);
}

int set_shape(map_t *map, int x, int y)
{
	sfVector2f square_pos[4] = {
		map->map_2d[y][x],
		map->map_2d[y][x + 1],
		map->map_2d[y + 1][x + 1],
		map->map_2d[y + 1][x],
	};

	for (int i = 0; i < 4; i++)
		sfConvexShape_setPoint(map->tiles[x][y].shape, i, square_pos[i]);
	return (0);
}

void set_vector(sfVector2i *vec, int x, int y)
{
	vec->x = x;
	vec->y = y;
}
