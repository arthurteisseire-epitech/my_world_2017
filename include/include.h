/*
** EPITECH PROJECT, 2017
** File Name : include.h
** File description:
** Ozz
*/
#ifndef INCLUDE_H
#define INCLUDE_H
#include <math.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#define ANGLE_X 45
#define ANGLE_Y 35
#define MAP_X 6
#define MAP_Y 6
#define OFSET_X 0
#define OFSET_Y 0
#define SCALE_X 1
#define SCALE_Y 1
#define SCALE_Z 1

sfVector2f project_iso_point(int x, int y, int z);
sfVector2f **create_map_2d(int **map_3d);

#endif
