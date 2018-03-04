/*
** EPITECH PROJECT, 2017
** File Name : save.c
** File description:
** by Arthur Teisseire
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_world.h"
#include "my.h"
#include "save.h"
#include "map.h"

int save_map(world_t *wd, char *pathname)
{
	int fd = open(pathname, O_CREAT | O_WRONLY,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (write_dimension(fd) == -1)
		return (-1);
	if (write_infos(wd, fd) == -1)
		return (-1);
	close(fd);
	return (0);
}

int write_infos(world_t *wd, int fd)
{
	for (int row = 0; row < NB_ROW; row++) {
		for (int col = 0; col < NB_COL; col++) {
			write_line(wd, fd, row, col);
		}	
	}
	return (0);
}

int write_line(world_t *wd, int fd, int row, int col)
{
	int index_texture = find_texture(wd, row, col);
	char *high = my_itoa(wd->map->map_3d[row][col]);
	char *index = my_itoa(index_texture);

	if (high == NULL || index == NULL)
		return (-1);
	write(fd, high, my_strlen(high));
	if (index_texture == -1)
		return (-1);
	write(fd, ",", 1);
	write(fd, index, my_strlen(index));
	write(fd, "\n", 1);
	free(index);
	free(high);
	return (0);
}

int find_texture(world_t *wd, int row, int col)
{
	const sfTexture *tx = sfConvexShape_getTexture(
			wd->map->tiles[row][col].shape);

	for (int i = 0; i < NB_TEXTURE; i++) {
		if (tx == wd->textures[i])
			return (i);
	}
	return (-1);
}

int write_dimension(int fd)
{
	char *row = my_itoa(NB_ROW + 1);
	char *col = my_itoa(NB_COL + 1);

	if (row == NULL || col == NULL)
		return (-1);
	write(fd, row, my_strlen(row));
	write(fd, "x", 1);
	write(fd, col, my_strlen(col));
	write(fd, "\n", 1);
	free(row);
	free(col);
	return (0);
}
