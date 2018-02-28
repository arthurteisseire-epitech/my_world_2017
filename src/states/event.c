/*
** EPITECH PROJECT, 2017
** File Name : event.c
** File description:
** By Arthur Teisseire
*/

#include "my_world.h"
#include "camera.h"
#include "input.h"

int event(world_t *wd)
{
	while (sfRenderWindow_pollEvent(wd->window, &wd->event)) {
		if (wd->event.type == sfEvtClosed)
			sfRenderWindow_close(wd->window);
		if (sfKeyboard_isKeyPressed(sfKeyEscape))
			sfRenderWindow_close(wd->window);
		move_offset_map(wd);
		scale_map(wd);
	}
	return (0);
}
