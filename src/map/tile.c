/*
** EPITECH PROJECT, 2017
** File Name : tile.c
** File description:
** Ozz
*/

#include "my_world.h"
#include "map.h"
#include <stdio.h>

sfVector2i get_sqr(world_t *wd, sfVector2i pt, char c)
{
	sfVector2i sqr = {-1, -1};

	if (c == 't') {
		sqr.x = wd->map->map_2d[pt.x][pt.y].x;
		sqr.y = wd->map->map_2d[pt.x][pt.y].y;
	} else if (c == 'l') {
		sqr.x = wd->map->map_2d[pt.x + 1][pt.y].x;
		sqr.y = wd->map->map_2d[pt.x + 1][pt.y].y;
	} else if (c == 'r') {
		sqr.x = wd->map->map_2d[pt.x][pt.y + 1].x;
		sqr.y = wd->map->map_2d[pt.x][pt.y + 1].y;
	} else if (c == 'b') {
		sqr.x = wd->map->map_2d[pt.x + 1][pt.y + 1].x;
		sqr.y = wd->map->map_2d[pt.x + 1][pt.y + 1].y;
	}
		return (sqr);
}

int is_det_pos(sfVector2i d, sfVector2i t)
{
	int det = d.x * t.y - d.y * t.x;

	if (det >= 0) {
		return (1);
	}
	else {
		return (-1);
	}
}

sfVector2i get_vec(sfVector2i vec_1, sfVector2i vec_2)
{
	sfVector2i vec;
 
	vec.x = vec_2.x - vec_1.x;
	vec.y = vec_2.y - vec_1.y;
	return (vec);
}

int tile_collide(world_t *wd, sfVector2i tile_index, sfVector2i pos)
{
	int point_inside = 0;
	sfVector2i d;
	sfVector2i t;
	sfVector2i tile[4] = {get_sqr(wd, tile_index, 't') ,
				get_sqr(wd, tile_index, 'r'),
				get_sqr(wd, tile_index, 'b'),
				get_sqr(wd, tile_index, 'l')};

	for (int i = 0; i < 4; i++) {
		t = get_vec(tile[i], pos);
		d = get_vec(tile[i], tile [(i + 1) % 4]);
		point_inside += is_det_pos(d, t);
	}
	if (point_inside == 4)
		return (1);
	else
		return (0);
}
