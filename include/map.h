/*
** EPITECH PROJECT, 2017
** File Name : map.h
** File description:
** by Arthur Teisseire
*/

#ifndef MAP_2D_H
#define MAP_2D_H

typedef struct camera camera_t;
typedef struct world world_t;

typedef struct tile {
	sfConvexShape *shape;
	sfVector2i top;
	sfVector2i left;
	sfVector2i right;
	sfVector2i bottom;
	sfVector2f pos_top;
	sfVector2f pos_left;
	sfVector2f pos_right;
	sfVector2f pos_bottom;
} tile_t;

typedef struct map {
	int **map_3d;
	sfVector2f **map_2d;
	tile_t **tiles;
} map_t;

sfVector2f project_iso_point(camera_t *cam, int x, int y, int z);
sfVector2f **create_map_2d(camera_t *cam, int **map_3d);
int draw_shape(world_t *wd, sfVector2f *square_pos);
int display_shape(world_t *wd, int x, int y);
int set_tiles_from_2d(map_t *map);
int set_map_2d(world_t *wd, int **map_3d);
int draw_map(world_t const * const wd);
int set_shape(map_t *map, int row, int col);
sfVector2i get_sqr(world_t *wd, sfVector2i pt, char c);
int tile_collide(world_t *wd, sfVector2i tile_index, sfVector2i pos);
void raise(world_t *wd, sfVector2i pt);
int update_shadow(map_t *map, int row, int col);
int reset_map_3d(int **map_3d);

#endif
