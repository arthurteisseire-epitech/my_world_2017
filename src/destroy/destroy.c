/*
** EPITECH PROJECT, 2017
** File Name : destroy.c
** File description:
** By Arthur Teisseire
*/

#include <stdlib.h>
#include "my_world.h"
#include "destroy.h"
#include "toolbar.h"
#include "map.h"

int destroy(world_t *wd)
{
	sfRenderWindow_destroy(wd->window);
	destroy_textures(wd->textures);
	free(wd->cam);
	free_map_3d(wd->map->map_3d);
	free_map_2d(wd->map->map_2d);
	free_toolbar(wd->toolbar);
	free_tiles(wd->map->tiles);
	free_stats(wd->stats);
	free(wd->map);
	return (0);
}

int destroy_textures(sfTexture **textures)
{
	for (int i = 0; i < NB_TEXTURE; i++)
		sfTexture_destroy(textures[i]);
	free(textures);
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

int free_toolbar(toolbar_t *toolbar)
{
	for (int i = 0; i < NB_TOOLS; i++)
		sfRectangleShape_destroy(toolbar->tool[i].rect);
	free(toolbar->tool);
	free(toolbar);
	return (0);
}
