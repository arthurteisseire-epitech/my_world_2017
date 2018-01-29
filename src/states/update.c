/*
** EPITECH PROJECT, 2017
** File Name : update.c
** File description:
** By Arthur Teisseire
*/

#include "my_world.h"
#include "screen.h"

int update(screen_t *sc)
{
	sfTexture_updateFromPixels(
		sc->texture, sc->buffer->pixels, WIDTH, HEIGHT, 0, 0);
	return (0);
}
