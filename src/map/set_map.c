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

int set_tiles_from_2d(world_t *wd)
{
	for (int row = 0; row < NB_ROW - 1; row++) {
		for (int col = 0; col < NB_COL - 1; col++) {
			set_shape(wd->map, row, col);
			update_shadow(wd->map, row, col);
			set_tile_shape(wd, &wd->map->tiles[row][col]);
		}
	}
	return (0);
}

int set_shape(map_t *map, int row, int col)
{
	sfVector2f square_pos[4] = {
		map->map_2d[row][col],
		map->map_2d[row][col + 1],
		map->map_2d[row + 1][col + 1],
		map->map_2d[row + 1][col],
	};

	for (int i = 0; i < 4; i++)
		sfConvexShape_setPoint(
			map->tiles[row][col].shape,
			i,
			square_pos[i]);
	return (0);
}

void set_tile_shape(world_t *wd, tile_t *tile)
{
	sfConvexShape_setTexture(tile->shape, wd->textures[0], sfTrue);
	sfConvexShape_setOutlineThickness(tile->shape, tile->outline);
	sfConvexShape_setOutlineColor(tile->shape, sfBlack);
}

void set_vec2f(sfVector2f *vec, float x, float y)
{
	vec->x = x;
	vec->y = y;
}
