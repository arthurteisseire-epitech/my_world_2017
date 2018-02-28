/*
** EPITECH PROJECT, 2017
** File Name : destroy.c
** File description:
** By Arthur Teisseire
*/

#include <stdlib.h>
#include "my_world.h"
#include "destroy.h"

int destroy(world_t *wd)
{
	sfRenderWindow_destroy(wd->window);
	free(wd->cam);
	free_map_3d(wd->map_3d);
	free_map_2d(wd->map_2d);
	return (0);
}

int free_map_2d(sfVector2f **map_2d)
{
	for (int row = 0; row < NB_ROW; row++) {
		free(map_2d[row]);
	}
	free(map_2d);
	return (0);
}

int free_map_3d(int **map_3d)
{
	for (int row = 0; row < NB_ROW; row++) {
		free(map_3d[row]);
	}
	free(map_3d);
	return (0);
}
