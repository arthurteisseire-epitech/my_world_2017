/*
** EPITECH PROJECT, 2017
** File Name : destroy.c
** File description:
** By Arthur Teisseire
*/

#include "my_world.h"
#include "screen.h"

int destroy(screen_t *sc)
{
	sfRenderWindow_destroy(sc->window);
	return (0);
}
