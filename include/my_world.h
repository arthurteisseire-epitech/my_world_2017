/*
** EPITECH PROJECT, 2017
** File Name : my_world.h
** File description:
** Ozz
*/

#ifndef MY_WORLD_H
#define MY_WORLD_H

#include <SFML/Graphics.h>
#include <math.h>
#include <stdlib.h>

#define WIDTH 1920
#define HEIGHT 1080
#define TITLE "my_world"
#define MAP_X 6
#define MAP_Y 6
#define ANGLE_X 45
#define ANGLE_Y 35
#define OFSET_X 600
#define OFSET_Y 0
#define SCALE_X 100
#define SCALE_Y 100
#define SCALE_Z 100

typedef struct camera camera_t;

sfVector2f project_iso_point(int x, int y, int z);

#endif
