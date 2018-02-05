/*
** EPITECH PROJECT, 2017
** File Name : destroy.c
** File description:
** By Arthur Teisseire
*/

#include "my_world.h"

int destroy(world_t *wd)
{
	sfRenderWindow_destroy(wd->window);
	return (0);
}
