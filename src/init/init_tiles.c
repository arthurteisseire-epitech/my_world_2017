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
		wd->map->tiles[row] = new_row(wd);
		if (wd->map->tiles[row] == NULL)
			return (-1);
	}
	return (0);
}

tile_t *new_row(world_t *wd)
{
	tile_t *row_tile = malloc(sizeof(tile_t) * NB_COL);

	if (row_tile == NULL)
		return (NULL);
	for (int col = 0; col < NB_COL; col++) {
		row_tile[col].shape = new_shape(wd);
		if (row_tile[col].shape == NULL)
			return (NULL);
	}
	return (row_tile);
}

sfConvexShape *new_shape(world_t *wd)
{
	sfConvexShape *shape = sfConvexShape_create();

	if (shape == NULL)
		return (NULL);
	sfConvexShape_setPointCount(shape, 4);
	sfConvexShape_setTexture(shape, wd->textures[0], sfTrue);
	sfConvexShape_setOutlineThickness(shape, 2.0);
	sfConvexShape_setOutlineColor(shape, sfBlack);
	return (shape);
}
