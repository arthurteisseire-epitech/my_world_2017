/*
** EPITECH PROJECT, 2017
** File Name : init.h
** File description:
** by Arthur Teisseire
*/

#ifndef INIT_H
#define INIT_H

typedef struct camera camera_t;
typedef struct world world_t;
typedef struct tool tool_t;
typedef struct map map_t;
typedef struct tile tile_t;

int init_world(world_t *wd);
int init_map(world_t *wd);
int init_map_3d(map_t *map);
int init_textures(world_t *wd);
int init_camera(world_t *wd);

int init_toolbar(world_t *wd);
int init_tools(toolbar_t *toolbar);
int set_rectangle(tool_t *tool);

sfRenderWindow *create_window(void);
int init_tiles(world_t *wd);
void set_vec2i(sfVector2i *vec, int row, int col);
tile_t *new_row(world_t *wd, int row);
sfConvexShape *new_shape(world_t *wd);

#endif
