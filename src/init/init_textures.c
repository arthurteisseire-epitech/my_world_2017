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
	wd->textures[0] = sfTexture_createFromFile("assets/background.png", NULL);
	wd->textures[1] = sfTexture_createFromFile("assets/grass.png", NULL);
	wd->textures[2] = sfTexture_createFromFile("assets/precision.png", NULL);
	wd->textures[3] = sfTexture_createFromFile("assets/grid.png", NULL);
	wd->textures[4] = sfTexture_createFromFile("assets/decrease.png", NULL);
	wd->textures[5] = sfTexture_createFromFile("assets/increase.png", NULL);
	wd->textures[6] = sfTexture_createFromFile("assets/low_force.png", NULL);
	wd->textures[7] = sfTexture_createFromFile("assets/high_force.png", NULL);
	wd->textures[8] = sfTexture_createFromFile("assets/save.png", NULL);
	if (wd->textures[0] == NULL ||
		wd->textures[1] == NULL ||
		wd->textures[2] == NULL ||
		wd->textures[3] == NULL ||
		wd->textures[4] == NULL ||
		wd->textures[5] == NULL ||
		wd->textures[6] == NULL ||
		wd->textures[7] == NULL ||
		wd->textures[8] == NULL)
		return (-1);
	return (0);
}
