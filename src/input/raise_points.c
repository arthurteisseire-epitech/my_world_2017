/*
** EPITECH PROJECT, 2017
** File Name : raise_points.c
** File description:
** by Arthur Teisseire
*/

#include "my_world.h"

int click(world_t *wd)
{
	if (wd->event.type == sfEvtMouseButtonPressed) {
		if (wd->event.mouseButton.button == sfMouseLeft)
			raise_point(wd);
	}
	return (0);
}

int raise_point(world_t *wd)
{
	for (int col = 0; col < NB_COL; col++) {
		check_row(wd, col);
	}
	return (0);
}

int check_row(world_t *wd, int col)
{
	for (int row = 0; row < NB_ROW; row++) {
		if (wd->map_2d[row][col] == wd->event.mouseButton.x)
	}
}
