/*
** EPITECH PROJECT, 2017
** File Name : init_tiles.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my_world.h"
#include "map.h"
#include "init.h"

int init_tiles(world_t *wd)
{
	wd->map->tiles = malloc(sizeof(tile_t *) * NB_ROW);

	if (wd->map->tiles == NULL)
		return (-1);
	for (int row = 0; row < NB_ROW; row++) {
		wd->map->tiles[row] = new_row(wd, row);
		if (wd->map->tiles[row] == NULL)
			return (-1);

	}
	return (0);
}

tile_t *new_row(world_t *wd, int row)
{
	tile_t *row_tile = malloc(sizeof(tile_t) * NB_COL);

	if (row_tile == NULL)
		return (NULL);
	for (int col = 0; col < NB_COL; col++) {
		new_shape(wd, &row_tile[col]);
		set_vec2i(&row_tile[col].top, row, col);
		set_vec2i(&row_tile[col].right, row, col + 1);
		set_vec2i(&row_tile[col].bottom, row + 1, col + 1);
		set_vec2i(&row_tile[col].left, row + 1, col);
		row_tile[col].outline = 2.0;
		if (row_tile[col].shape == NULL)
			return (NULL);
	}
	return (row_tile);
}

int new_shape(world_t *wd, tile_t *tile)
{
	tile->shape = sfConvexShape_create();
	if (tile->shape == NULL)
		return (-1);
	sfConvexShape_setPointCount(tile->shape, 4);
	set_tile_shape(wd, tile);
	return (0);
}

void set_vec2i(sfVector2i *vec, int row, int col)
{
	vec->x = row;
	vec->y = col;
}
