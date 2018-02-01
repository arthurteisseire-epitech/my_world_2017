/*
** EPITECH PROJECT, 2017
** File Name : screen.h
** File description:
** by Arthur Teisseire
*/

#ifndef SCREEN_H
#define SCREEN_H

#include <SFML/Graphics.h>

typedef struct world {
	sfEvent event;
	sfRenderWindow *window;
	int **map_3d;
	sfVector2f **map_2d;
} world_t;

int init_world(world_t *wd);
int init_map(world_t *wd);
sfRenderWindow *create_window(void);

sfVector2f project_iso_point(int x, int y, int z);
sfVector2f **create_map_2d(int **map_3d);
void draw_line(sfRenderWindow *window, sfVector2f point_a, sfVector2f point_b);
void display_grid_point(world_t *wd, int x, int y);
void draw_map_2d(world_t *wd);

#endif
