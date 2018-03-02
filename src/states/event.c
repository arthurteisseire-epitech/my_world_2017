/*
** EPITECH PROJECT, 2017
** File Name : event.c
** File description:
** By Arthur Teisseire
*/

#include "my_world.h"
#include "camera.h"
#include "input.h"
#include "toolbar.h"

sfVector2i get_mouse_pos(sfEvent event)
{
	sfVector2i pos;

	pos.x = event.mouseButton.x;
	pos.y = event.mouseButton.y;
	return (pos);
}

static int handle_click(world_t *wd)
{
	if (wd->event.type == sfEvtMouseButtonPressed) {
		if (wd->event.mouseButton.button == sfMouseLeft)
			wd->toolbar->increasing = 1;
		if (wd->event.mouseButton.button == sfMouseRight)
			wd->toolbar->increasing = 0;
		check_map_2d(wd, get_mouse_pos(wd->event));
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
		if (update_tools(wd) == 0)
			return (1);
		handle_click(wd);
		move_offset_map(wd);
		scale_map(wd);
	}
	return (0);
}
