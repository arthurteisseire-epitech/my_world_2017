/*
** EPITECH PROJECT, 2017
** File Name : init_world.c
** File description:
** By Arthur Teisseire
*/

#include "my_world.h"
#include "world_struct.h"

int init_world(world_t *wd)
{
	int status;

	wd->window = create_window();
	if (wd->window == NULL)
		return (-1);
	status = init_map(wd);
	if (status == -1)
		return (-1);
	wd->map_2d = create_map_2d(wd->map_3d);
	return (0);
}

int init_map(world_t *wd)
{
	wd->map_3d = malloc(sizeof(int *) * MAP_Y);

	if (wd->map_3d == NULL)
		return (-1);
	for (int y = 0; y < MAP_Y; y++) {
		wd->map_3d[y] = malloc(sizeof(int) * MAP_X);
		if (wd->map_3d[y] == NULL)
			return (-1);
		for (int x = 0; x < MAP_X; x++)
			wd->map_3d[y][x] = 0;
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
