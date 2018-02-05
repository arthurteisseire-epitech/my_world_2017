/*
** EPITECH PROJECT, 2017
** File Name : camera.h
** File description:
** by Arthur Teisseire
*/

#ifndef CAMERA_H
#define CAMERA_H

typedef struct camera {
	sfVector3f scale;
	sfVector2f offset;
	sfVector2f angle;
} camera_t;

int init_camera(world_t *wd);

#endif
