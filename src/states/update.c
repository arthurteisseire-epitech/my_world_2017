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
#include "text.h"

int update(world_t *wd)
{
	set_map(wd, wd->map->map_3d);
	return (0);
}
