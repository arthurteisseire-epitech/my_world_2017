/*
** EPITECH PROJECT, 2017
** File Name : event.c
** File description:
** By Arthur Teisseire
*/

#include "my_world.h"
#include "camera.h"
#include "input.h"
#include "stats.h"
#include "map.h"
#include "toolbar.h"

static void handle_exit(world_t *wd)
{
	if (wd->event.type == sfEvtClosed)
		sfRenderWindow_close(wd->window);
	if (sfKeyboard_isKeyPressed(sfKeyEscape))
		sfRenderWindow_close(wd->window);
}

sfVector2i get_mouse_pos(sfEvent *event)
{
	sfVector2i pos;

	pos.x = event->mouseButton.x;
	pos.y = event->mouseButton.y;
	return (pos);
}

static void handle_click(world_t *wd)
{
	if (wd->event.type == sfEvtMouseButtonPressed) {
		if (wd->event.mouseButton.button == sfMouseLeft)
			wd->stats->increasing = 1;
		if (wd->event.mouseButton.button == sfMouseRight)
			wd->stats->increasing = 0;
		check_map_2d(wd, get_mouse_pos(&wd->event));
	}
}

static void reset_map(world_t *wd)
{
	if (sfKeyboard_isKeyPressed(sfKeySpace))
		reset_map_3d(wd);
}

int event(world_t *wd)
{
	while (sfRenderWindow_pollEvent(wd->window, &wd->event)) {
		handle_exit(wd);
		if (update_tools(wd) == 0)
			return (1);
		reset_map(wd);
		handle_click(wd);
		move_offset_map(wd);
		scale_map(wd);
		incline_map(wd);
	}
	return (0);
}
