/*
** EPITECH PROJECT, 2017
** File Name : init_screen.c
** File description:
** By Arthur Teisseire
*/

#include "my_world.h"
#include "screen.h"

void init_screen(screen_t *sc)
{
	sc->window = create_window();
}

sfRenderWindow *create_window(void)
{
	sfVideoMode mode = {WIDTH, HEIGHT, BIT_PER_PIXEL};
	sfRenderWindow *window;

	window = sfRenderWindow_create(
		mode, TITLE, sfResize | sfFullscreen | sfClose, NULL
	);
	if (!window)
		return (NULL);
	sfRenderWindow_setFramerateLimit(window, 60);
	return (window);
}
