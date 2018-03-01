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
#define NB_COL 20
#define NB_ROW 20
#define NB_TEXTURE 1

typedef struct camera camera_t;
typedef struct toolbar toolbar_t;
typedef struct map map_t;

typedef struct world {
	camera_t *cam;
	sfEvent event;
	sfRenderWindow *window;
	sfTexture **textures;
	toolbar_t *toolbar;
	map_t *map;
} world_t;

int run(void);

#endif
