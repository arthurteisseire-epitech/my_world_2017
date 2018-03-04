/*
** EPITECH PROJECT, 2017
** File Name : free_tiles.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my_world.h"
#include "map.h"
#include "destroy.h"

int free_tiles(world_t *wd)
{
	tile_t **tiles = wd->map->tiles;

	for (int row = 0; row < wd->nb_row; row++) {
		for (int col = 0; col < wd->nb_col; col++)
			sfConvexShape_destroy(tiles[row][col].shape);
		free(tiles[row]);
	}
	free(tiles);
	return (0);
}
