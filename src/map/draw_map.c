/*
** EPITECH PROJECT, 2017
** File Name : draw_map.c
** File description:
** by Arthur Teisseire
*/

#include "my_world.h"
#include "map.h"

int draw_map(world_t const * const wd)
{
	for (int row = 0; row < NB_ROW; row++)
		for (int col = 0; col < NB_COL; col++)
			sfRenderWindow_drawConvexShape(wd->window,
			wd->map->tiles[row][col].shape,
			NULL);
	return (0);
}
