/*
** EPITECH PROJECT, 2017
** File Name : event.c
** File description:
** By Arthur Teisseire
*/

#include "my_world.h"
#include "screen.h"

int event(screen_t *sc)
{
	while (sfRenderWindow_pollEvent(sc->window, &sc->event)) {
		if (sc->event.type == sfEvtClosed)
			sfRenderWindow_close(sc->window);
	}
	return (0);
}
