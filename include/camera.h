/*
** EPITECH PROJECT, 2017
** File Name : camera.h
** File description:
** by Arthur Teisseire
*/

#ifndef CAMERA_H
#define CAMERA_H

typedef struct camera {
	sfVector2f offset;
	sfVector3f scale;
} camera_t;

int init_camera(world_t *wd);

#endif
