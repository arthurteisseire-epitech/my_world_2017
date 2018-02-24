/*
** EPITECH PROJECT, 2017
** File Name : event.c
** File description:
** By Arthur Teisseire
*/

#include "my_world.h"
#include "camera.h"

static int move_offset_map(world_t *wd)
{
	if (sfKeyboard_isKeyPressed(sfKeyRight)) {
		wd->cam->offset.x -= 10;
		wd->cam->offset.y += 10;
	}
	if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
		wd->cam->offset.x += 10;
		wd->cam->offset.y -= 10;
	}
	if (sfKeyboard_isKeyPressed(sfKeyUp)) {
		wd->cam->offset.x += 10;
		wd->cam->offset.y += 10;
	}
	if (sfKeyboard_isKeyPressed(sfKeyDown)) {
		wd->cam->offset.x -= 10;
		wd->cam->offset.y -= 10;
	}
	return (0);
}

int event(world_t *wd)
{
	while (sfRenderWindow_pollEvent(wd->window, &wd->event)) {
		if (wd->event.type == sfEvtClosed)
			sfRenderWindow_close(wd->window);
		if (sfKeyboard_isKeyPressed(sfKeyEscape))
			sfRenderWindow_close(wd->window);
		move_offset_map(wd);
	}
	return (0);
}
