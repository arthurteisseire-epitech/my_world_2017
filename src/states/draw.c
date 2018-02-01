/*
** EPITECH PROJECT, 2017
** File Name : disp.c
** File description:
** By Arthur Teisseire
*/

#include "my_world.h"
#include "world_struct.h"

int draw(world_t *wd)
{
	sfRenderWindow_clear(wd->window, sfBlack);
	sfRenderWindow_display(wd->window);
	return (0);
}
