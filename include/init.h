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

int init_world(world_t *wd);
int init_map(world_t *wd);
int init_textures(world_t *wd);
int init_camera(world_t *wd);
sfRenderWindow *create_window(void);

#endif
