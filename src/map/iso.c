/*
** EPITECH PROJECT, 2017
** File Name : iso.c
** File description:
** Ozz
*/

#include <math.h>
#include "my_world.h"
#include "camera.h"

sfVector2f project_iso_point(camera_t *cam, int x, int y, int z)
{
	sfVector2f point_2d;

	point_2d.x = cos(cam->angle.x) * x - cos(cam->angle.x) * y;
	point_2d.y = -(sin(cam->angle.y) * y + sin(cam->angle.y) * x - z);
	return (point_2d);
}
