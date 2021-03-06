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
int check_row(world_t *wd, sfVector2i pos, sfVector2i pt);
int incline_map(world_t *wd);
void raise_tile(world_t *wd, sfVector2i pt);

#endif
