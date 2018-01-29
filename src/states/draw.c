/*
** EPITECH PROJECT, 2017
** File Name : disp.c
** File description:
** By Arthur Teisseire
*/

#include "my_world.h"
#include "screen.h"

int draw(screen_t *sc)
{
	sfRenderWindow_clear(sc->window, sfBlack);
	sfRenderWindow_display(sc->window);
	return (0);
}
