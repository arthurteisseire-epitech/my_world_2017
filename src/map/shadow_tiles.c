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
	float tile_height = map->map_2d[row + 1][col + 1].y -
				map->map_2d[row][col].y;
	float tile_width = map->map_2d[row][col + 1].x -
				map->map_2d[row + 1][col].x;
	int intensity = 255 - (tile_width / tile_height) * 40;

	return (intensity < 130 ? 130 : intensity);
}

int update_shadow(map_t *map, int row, int col)
{
	int intensity = get_shadow_intensity(map, row, col);
	sfColor shadow_color = {intensity, intensity, intensity, 255};

	sfConvexShape_setFillColor(map->tiles[row][col].shape, shadow_color);
	return (0);
}
