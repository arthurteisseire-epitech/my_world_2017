/*
** EPITECH PROJECT, 2017
** File Name : map_2d.h
** File description:
** by Arthur Teisseire
*/

#ifndef MAP_2D_H
#define MAP_2D_H

typedef struct camera camera_t;
typedef struct world world_t;

sfVector2f project_iso_point(camera_t *cam, int x, int y, int z);
sfVector2f **create_map_2d(camera_t *cam, int **map_3d);
void draw_line(world_t *wd, sfVector2f point_a, sfVector2f point_b);
void display_grid_point(world_t *wd, int x, int y);
void draw_map_2d(world_t *wd);

#endif
