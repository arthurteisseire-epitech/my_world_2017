/*
** EPITECH PROJECT, 2017
** File Name : init_camera.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my_world.h"
#include "camera.h"

int init_camera(world_t *wd)
{
	wd->cam = malloc(sizeof(camera_t));
	if (wd->cam == NULL)
		return (-1);
	wd->cam->scale.x = 200;
	wd->cam->scale.y = 200;
	wd->cam->scale.z = 200;
	wd->cam->offset.x = WIDTH / 2;
	wd->cam->offset.y = -HEIGHT / 2;
	wd->cam->angle.x = 45;
	wd->cam->angle.y = 35;
	return (0);
}
