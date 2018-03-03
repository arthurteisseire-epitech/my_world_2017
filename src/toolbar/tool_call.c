/*
** EPITECH PROJECT, 2017
** File Name : tool_call.c
** File description:
** by Arthur Teisseire
*/

#include "my_world.h"
#include "toolbar.h"
#include "map.h"

int toggle_raise_mode(world_t *wd)
{
	wd->toolbar->raise_mode = !wd->toolbar->raise_mode;
	return (0);
}

int toggle_grid(world_t *wd)
{
	tile_t *tile;
	float outline = 0;

	if (wd->map->tiles[0][0].outline == 0)
		outline += 2;
	for (int row = 0; row < NB_ROW; row++) {
		for (int col = 0; col < NB_ROW; col++) {
			tile = &wd->map->tiles[row][col];
			tile->outline = outline;
		}
	}
	return (0);
}

int increase_radius(world_t *wd)
{
	wd->toolbar->radius += 1;
	return (0);
}

int decrease_radius(world_t *wd)
{
	if (wd->toolbar->radius > 1)
		wd->toolbar->radius -= 1;
	return (0);
}
