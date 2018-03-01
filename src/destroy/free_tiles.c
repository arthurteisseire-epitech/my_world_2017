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

int free_tiles(tile_t **tiles)
{
	for (int row = 0; row < NB_ROW; row++) {
		for (int col = 0; col < NB_COL; col++)
			sfConvexShape_destroy(tiles[row][col].shape);
		free(tiles[row]);
	}
	free(tiles);
	return (0);
}
