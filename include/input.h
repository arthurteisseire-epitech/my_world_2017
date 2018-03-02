/*
** EPITECH PROJECT, 2017
** File Name : input.h
** File description:
** by Arthur Teisseire
*/

#ifndef INPUT_H
#define INPUT_H

int move_offset_map(world_t *wd);
int scale_map(world_t *wd);
int check_map_2d(world_t *wd, sfVector2i pos);
int incline_map(world_t *wd);

#endif
