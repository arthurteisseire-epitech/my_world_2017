/*
** EPITECH PROJECT, 2017
** File Name : disp.c
** File description:
** By Arthur Teisseire
*/

#include <stdlib.h>
#include "my_world.h"
#include "map_2d.h"
#include "destroy.h"

int draw(world_t *wd)
{
	sfRenderWindow_clear(wd->window, sfBlack);
	if (wd->map_2d)
		free_map_2d(wd->map_2d);
	wd->map_2d = create_map_2d(wd->cam, wd->map_3d);
	draw_map_2d(wd);
	sfRenderWindow_display(wd->window);
	return (0);
}
