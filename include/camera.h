/*
** EPITECH PROJECT, 2017
** File Name : camera.h
** File description:
** by Arthur Teisseire
*/

#ifndef CAMERA_H
#define CAMERA_H

#define ANGLE_STEP 0.005
#define MAX_ANGLE 35 + (ANGLE_STEP * 40)
#define MIN_ANGLE 35 - (ANGLE_STEP * 80)
#define ZOOM_SPEED 1.5

typedef struct camera {
	sfVector3f scale;
	sfVector2f offset;
	sfVector2f angle;
} camera_t;

#endif
