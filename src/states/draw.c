/*
** EPITECH PROJECT, 2017
** File Name : disp.c
** File description:
** By Arthur Teisseire
*/

#include <stdlib.h>
#include "my_world.h"
#include "map_2d.h"

int draw(world_t *wd)
{
	sfRenderWindow_clear(wd->window, sfBlack);
	draw_map_2d(wd);
	sfRenderWindow_display(wd->window);
	return (0);
}
