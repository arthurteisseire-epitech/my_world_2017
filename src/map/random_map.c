/*
** EPITECH PROJECT, 2017
** File Name : random_map.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my_world.h"
#include "map.h"
#include "init.h"
#include "input.h"

void random_map(world_t *wd)
{
	for (int row = 0; row < wd->nb_row; row++)
		random_row(wd, row);
}

void random_row(world_t *wd, int row)
{
	sfVector2i pos;

	for (int col = 0; col < wd->nb_col; col++) {
		if (rand() % 3 == 0) {
			set_vec2i(&pos, row, col);
			raise_tile(wd, pos);
		}
	}
}
