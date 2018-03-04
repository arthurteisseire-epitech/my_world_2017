/*
** EPITECH PROJECT, 2017
** File Name : destroy.h
** File description:
** by Arthur Teisseire
*/

#ifndef DESTROY_H
#define DESTROY_H

typedef struct tile tile_t;

int destroy(world_t *wd);
int free_map_2d(world_t *wd);
int free_map_3d(world_t *wd);
int destroy_textures(sfTexture **textures);
int free_toolbar(toolbar_t *toolbar);
int free_tiles(world_t *wd);
int free_stats(stats_t *stats);

#endif
