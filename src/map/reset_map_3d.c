/*
** EPITECH PROJECT, 2017
** File Name : reset_map_3d.c
** File description:
** by Arthur Teisseire
*/

#include "my_world.h"
#include "map.h"

int reset_map_3d(world_t *wd)
{
	for (int row = 0; row < wd->nb_row; row++) {
		for (int col = 0; col < wd->nb_col; col++) {
			wd->map->map_3d[row][col] = 0;
		}
	}
	return (0);
}
