/*
** EPITECH PROJECT, 2017
** File Name : update.c
** File description:
** By Arthur Teisseire
*/

#include "my_world.h"
#include "map_2d.h"
#include "destroy.h"

int update(world_t *wd)
{
	if (wd->map_2d)
		free_map_2d(wd->map_2d);
	wd->map_2d = create_map_2d(wd->cam, wd->map_3d);
	return (0);
}
