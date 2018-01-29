/*
** EPITECH PROJECT, 2017
** File Name : init_screen.c
** File description:
** By Arthur Teisseire
*/

#include "my_world.h"
#include "screen.h"

int init_screen(screen_t *sc)
{
	int status;

	sc->window = create_window();
	if (sc->window == NULL)
		return (-1);
	status = init_map(sc);
	if (status == -1)
		return (-1);
	sc->map_2d = create_map_2d(sc->map_3d);
	return (0);
}

int init_map(screen_t *sc)
{
	sc->map_3d = malloc(sizeof(int *) * MAP_Y);

	if (sc->map_3d == NULL)
		return (-1);
	for (int y = 0; y < MAP_Y; y++) {
		sc->map_3d[y] = malloc(sizeof(int) * MAP_X);
		if (sc->map_3d[y] == NULL)
			return (-1);
		for (int x = 0; x < MAP_X; x++)
			sc->map_3d[y][x] = 0;
	}
	return (0);
}

sfRenderWindow *create_window(void)
{
	sfVideoMode mode = {WIDTH, HEIGHT, 32};
	sfRenderWindow *window;

	window = sfRenderWindow_create(
		mode, TITLE, sfResize | sfFullscreen | sfClose, NULL
	);
	if (!window)
		return (NULL);
	sfRenderWindow_setFramerateLimit(window, 60);
	return (window);
}
