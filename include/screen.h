/*
** EPITECH PROJECT, 2017
** File Name : screen.h
** File description:
** by Arthur Teisseire
*/

#ifndef SCREEN_H
#define SCREEN_H

#include <SFML/Graphics.h>

typedef struct screen {
	sfEvent event;
	sfRenderWindow *window;
	int **map_3d;
	sfVector2f **map_2d;
} screen_t;

int init_screen(screen_t *sc);
int init_map(screen_t *sc);
sfRenderWindow *create_window(void);

sfVector2f project_iso_point(int x, int y, int z);
sfVector2f **create_map_2d(int **map_3d);
void draw_line(sfRenderWindow *window, sfVector2f point_a, sfVector2f point_b);
void display_grid_point(screen_t *sc, int x, int y);
void draw_map_2d(screen_t *sc);

#endif
