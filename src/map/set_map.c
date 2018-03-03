/*
** EPITECH PROJECT, 2017
** File Name : convex.c
** File description:
** by Arthur Teisseire
*/

#include "my_world.h"
#include "map.h"
#include "camera.h"

int set_map(world_t *wd, int **map_3d)
{
	for (int row = 0; row < NB_ROW; row++) {
		for (int col = 0; col < NB_COL; col++) {
			wd->map->map_2d[row][col] = project_iso_point(
			wd->cam,
			col * wd->cam->scale.x + wd->cam->offset.x, 
			row * wd->cam->scale.y + wd->cam->offset.y, 
			map_3d[row][col] * wd->cam->scale.z);
			set_tile(wd, row, col);
		}
	}
	return (0);
}

void set_tile(world_t *wd, int row, int col)
{
	row--;
	col--;
	if (row >= 0 && col >= 0) {
		set_shape(wd->map, row, col);
		update_shadow(wd->map, row, col);
	}
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
