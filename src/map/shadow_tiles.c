/*
** EPITECH PROJECT, 2017
** File Name : shadow_tiles.c
** File description:
** by Arthur Teisseire
*/

#include "my_world.h"
#include "map.h"

static char get_shadow_intensity(map_t *map, int row, int col)
{
	sfVector2f top = map->map_2d[row][col];
	sfVector2f right = map->map_2d[row][col + 1];
	sfVector2f left = map->map_2d[row + 1][col];
	sfVector2f bottom = map->map_2d[row + 1][col + 1];
	float tile_height = bottom.y - top.y;
	float tile_width = right.x - left.x;
	int intensity = 255 - (tile_width / tile_height) * 35;

	return (intensity < 130 ? 130 : intensity);
}

int update_shadow(map_t *map, int row, int col)
{
	tile_t *tile = &map->tiles[row][col];
	int intensity = get_shadow_intensity(map, row, col);
	sfColor shadow_color = {intensity, intensity, intensity, 255};

	sfConvexShape_setFillColor(tile->shape, shadow_color);
	return (0);
}
