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
	if (sfKeyboard_isKeyPressed(sfKeyD)) {
		wd->cam->offset.x -= 10;
		wd->cam->offset.y += 10;
	}
	if (sfKeyboard_isKeyPressed(sfKeyQ)) {
		wd->cam->offset.x += 10;
		wd->cam->offset.y -= 10;
	}
	if (sfKeyboard_isKeyPressed(sfKeyZ)) {
		wd->cam->offset.x += 10;
		wd->cam->offset.y += 10;
	}
	if (sfKeyboard_isKeyPressed(sfKeyS)) {
		wd->cam->offset.x -= 10;
		wd->cam->offset.y -= 10;
	}
	return (0);
}

int scale_map(world_t *wd)
{
	float delta = wd->event.mouseWheelScroll.delta;

	if (wd->event.type == sfEvtMouseWheelScrolled && 
	wd->cam->scale.x + delta * ZOOM_SPEED > 0) {
		wd->cam->scale.x += delta * ZOOM_SPEED;
		wd->cam->scale.y += delta * ZOOM_SPEED;
		wd->cam->scale.z += delta * ZOOM_SPEED / 10;
	}
	return (0);
}

int incline_map(world_t *wd)
{
	sfVector2f *angle = &wd->cam->angle;

	if (sfKeyboard_isKeyPressed(sfKeyUp) && angle->y < MAX_ANGLE) {
		angle->y += ANGLE_STEP;
	}
	if (sfKeyboard_isKeyPressed(sfKeyDown) && angle->y > MIN_ANGLE) {
		angle->y -= ANGLE_STEP;
	}
	return (0);
}
