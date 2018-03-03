/*
** EPITECH PROJECT, 2017
** File Name : init_textures.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my_world.h"

int init_textures(world_t *wd)
{
	wd->textures = malloc(sizeof(sfTexture *) * NB_TEXTURE);
	if (wd->textures == NULL)
		return (-1);
	wd->textures[0] = sfTexture_createFromFile("assets/grass.png", NULL);
	if (wd->textures[0] == NULL)
		return (-1);
	wd->textures[1] = sfTexture_createFromFile("assets/precision.png", NULL);
	if (wd->textures[1] == NULL)
		return (-1);
	wd->textures[2] = sfTexture_createFromFile("assets/grid.png", NULL);
	if (wd->textures[2] == NULL)
		return (-1);
	wd->textures[3] = sfTexture_createFromFile("assets/increase.png", NULL);
	if (wd->textures[3] == NULL)
		return (-1);
	wd->textures[4] = sfTexture_createFromFile("assets/decrease.png", NULL);
	if (wd->textures[4] == NULL)
		return (-1);
	return (0);
}
