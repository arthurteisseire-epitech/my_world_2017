/*
** EPITECH PROJECT, 2017
** File Name : init_textures.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my_world.h"
#include "init.h"

int init_textures(world_t *wd)
{
	sfTexture **textures;

	wd->textures = malloc(sizeof(sfTexture *) * NB_TEXTURE);
	if (wd->textures == NULL)
		return (-1);
	textures = wd->textures;
	textures[0] = sfTexture_createFromFile("assets/background.png", NULL);
	textures[1] = sfTexture_createFromFile("assets/grass.png", NULL);
	textures[2] = sfTexture_createFromFile("assets/precision.png", NULL);
	textures[3] = sfTexture_createFromFile("assets/grid.png", NULL);
	textures[4] = sfTexture_createFromFile("assets/decrease.png", NULL);
	textures[5] = sfTexture_createFromFile("assets/increase.png", NULL);
	textures[6] = sfTexture_createFromFile("assets/low_force.png", NULL);
	textures[7] = sfTexture_createFromFile("assets/high_force.png", NULL);
	textures[8] = sfTexture_createFromFile("assets/save.png", NULL);
	if (check_textures(textures) == -1)
		return (-1);
	return (0);
}

int check_textures(sfTexture **textures)
{
	if (textures[0] == NULL ||
		textures[1] == NULL ||
		textures[2] == NULL ||
		textures[3] == NULL ||
		textures[4] == NULL ||
		textures[5] == NULL ||
		textures[6] == NULL ||
		textures[7] == NULL ||
		textures[8] == NULL)
		return (-1);
	return (0);
}
