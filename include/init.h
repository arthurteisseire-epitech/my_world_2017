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
int init_map_arrays(world_t *wd);
int init_map_3d(world_t *wd);
int init_textures(world_t *wd);
int init_camera(world_t *wd);
int init_clock(world_t *wd);
int init_stats(world_t *wd);
int init_background(world_t *wd);

int init_toolbar(world_t *wd);
int init_tools(toolbar_t *toolbar);
int set_rectangle(tool_t *tool);

int check_textures(sfTexture **textures);
sfRenderWindow *create_window(void);
int init_tiles(world_t *wd);
void set_vec2i(sfVector2i *vec, int row, int col);
tile_t *new_row(world_t *wd, int row);
int new_shape(world_t *wd, tile_t *tile);
void set_tool_image(world_t *wd);
int init_text(world_t *wd);

#endif
