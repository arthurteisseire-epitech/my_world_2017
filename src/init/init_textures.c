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
	wd->textures[0] = sfTexture_createFromFile("assets/bsd.png", NULL);
	if (wd->textures[0] == NULL)
		return (-1);
	return (0);
}