/*
** EPITECH PROJECT, 2017
** File Name : my_world.h
** File description:
** Ozz
*/

#ifndef MY_WORLD_H
#define MY_WORLD_H

#include <SFML/Graphics.h>

#define WIDTH 1920
#define HEIGHT 1080
#define TITLE "my_world"
#define MAP_X 6
#define MAP_Y 6

typedef struct camera camera_t;

typedef struct world {
	camera_t *cam;
	sfEvent event;
	sfRenderWindow *window;
	int **map_3d;
	sfVector2f **map_2d;
} world_t;

#endif
