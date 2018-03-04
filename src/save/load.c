/*
** EPITECH PROJECT, 2017
** File Name : load.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include <fcntl.h>
#include "my.h"
#include "my_world.h"
#include "map.h"
#include "save.h"

int load_map(world_t *wd, char *pathname)
{
	int fd = open(pathname, O_RDONLY);

	if (fd == -1)
		return (-1);
	if (load_dimension(wd, fd) == -1)
		return (-1);
	if (load_infos(wd, fd) == -1)
		return (-1);
	return (0);
}

int load_infos(world_t *wd, int fd)
{
	int index = 0;
	char *line = get_next_line(fd);

	while (line != NULL) {
		set_info(wd, line, index);
		free(line);
		line = get_next_line(fd);
		index++;
	}
	return (0);
}

int set_info(world_t *wd, char *line, int index)
{
	char **tokens = split(line, ", \t");
	int row = index / wd->nb_col;
	int col = index % wd->nb_col;
	tile_t *tile = &wd->map->tiles[row][col];
	int index_texture;

	if (tokens == NULL)
		return (-1);
	if (len_tokens(tokens) != 2) {
		free_tokens(tokens);
		return (-1);
	}
	index_texture = my_atoi(tokens[1]);
	wd->map->map_3d[row][col] = my_atoi(tokens[0]);
	sfConvexShape_setTexture(tile->shape, wd->textures[index_texture], sfFalse);
	free_tokens(tokens);
	return (0);
}

int load_dimension(world_t *wd, int fd)
{
	char *dimension = get_next_line(fd);
	char **tokens;
	
	if (dimension == NULL)
		return (-1);
	tokens = split(dimension, "x \t");
	free(dimension);
	if (tokens == NULL)
		return (-1);
	if (len_tokens(tokens) != 2) {
		free_tokens(tokens);
		return (-1);
	}
	wd->nb_row = my_atoi(tokens[0]) - 1;
	wd->nb_col = my_atoi(tokens[1]) - 1;
	free_tokens(tokens);
	return (0);
}
