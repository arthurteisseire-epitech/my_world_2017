/*
** EPITECH PROJECT, 2017
** File Name : tool_scale.c
** File description:
** by Arthur Teisseire
*/

#include "my_world.h"
#include "toolbar.h"
#include "map.h"
#include "stats.h"

int increase_radius(world_t *wd)
{
	wd->stats->radius += 1;
	return (0);
}

int decrease_radius(world_t *wd)
{
	if (wd->stats->radius > 1)
		wd->stats->radius -= 1;
	return (0);
}

int increase_force(world_t *wd)
{
	wd->stats->force += 1;
	return (0);
}

int decrease_force(world_t *wd)
{
	if (wd->stats->force > 1)
		wd->stats->force -= 1;
	return (0);
}
