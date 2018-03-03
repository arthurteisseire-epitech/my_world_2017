/*
** EPITECH PROJECT, 2017
** File Name : update.c
** File description:
** By Arthur Teisseire
*/

#include "my_world.h"
#include "map.h"
#include "destroy.h"
#include "toolbar.h"

int update(world_t *wd)
{
	set_map_2d(wd, wd->map->map_3d);
	set_tiles_from_2d(wd);
	return (0);
}
