/*
** EPITECH PROJECT, 2017
** File Name : move_map.c
** File description:
** by Arthur Teisseire
*/

#include "my_world.h"
#include "camera.h"

int move_offset_map(world_t *wd)
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

int scale_map(world_t *wd)
{
	if (wd->event.type == sfEvtMouseWheelScrolled) {
		wd->cam->scale.x += wd->event.mouseWheelScroll.delta * 3;
		wd->cam->scale.y += wd->event.mouseWheelScroll.delta * 3;
		wd->cam->scale.z += wd->event.mouseWheelScroll.delta * 0.3;
	}
	return (0);
}
