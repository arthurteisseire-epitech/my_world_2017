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

#define WIDTH 800
#define HEIGHT 600
#define TITLE "my_world"
#define MAP_X 6
#define MAP_Y 6
#define ANGLE_X 45
#define ANGLE_Y 35
#define OFSET_X 0
#define OFSET_Y 0
#define SCALE_X 1
#define SCALE_Y 1
#define SCALE_Z 1

sfVector2f project_iso_point(int x, int y, int z);
sfVector2f **create_map_2d(int **map_3d);

#endif
