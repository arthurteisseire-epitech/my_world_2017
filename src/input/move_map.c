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
