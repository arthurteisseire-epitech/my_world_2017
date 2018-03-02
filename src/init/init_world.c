/*
** EPITECH PROJECT, 2017
** File Name : init_world.c
** File description:
** By Arthur Teisseire
*/

#include <stdlib.h>
#include "my_world.h"
#include "camera.h"
#include "init.h"
#include "map.h"

int init_world(world_t *wd)
{
	wd->window = create_window();
	if (wd->window == NULL ||
	init_camera(wd) == -1 ||
	init_map(wd) == -1 ||
	init_textures(wd) == -1 ||
	init_toolbar(wd) == -1 ||
	init_tiles(wd) == -1)
		return (-1);
	return (0);
}

sfRenderWindow *create_window(void)
{
	sfVideoMode mode = {WIDTH, HEIGHT, 32};
	sfRenderWindow *window;

	window = sfRenderWindow_create(
		mode, TITLE, sfResize | sfFullscreen | sfClose, NULL);
	if (!window)
		return (NULL);
	sfRenderWindow_setFramerateLimit(window, 60);
	return (window);
}
