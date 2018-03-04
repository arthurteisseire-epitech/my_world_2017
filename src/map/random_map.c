/*
** EPITECH PROJECT, 2017
** File Name : random_map.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my_world.h"
#include "map.h"

int random_map(world_t *wd)
{
	for (int row = 0; row < wd->nb_row; row++) {
		for (int col = 0; col < wd->nb_col; col++) {
			wd->map->map_3d[row][col] = rand() % 20;
		}
	}
	return (0);
}
