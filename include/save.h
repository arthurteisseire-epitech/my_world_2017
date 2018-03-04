/*
** EPITECH PROJECT, 2017
** File Name : save.h
** File description:
** by Arthur Teisseire
*/

#ifndef SAVE_H
#define SAVE_H

int save_map(world_t *wd, char *pathname);
int write_infos(world_t *wd, int fd);
int write_line(world_t *wd, int fd, int row, int col);
int find_texture(world_t *wd, int row, int col);
int write_dimension(int fd);

#endif
