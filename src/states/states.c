/*
** EPITECH PROJECT, 2017
** File Name : states.c
** File description:
** by Arthur Teisseire
*/

#include "my_world.h"
#include "states.h"

int states(world_t *wd)
{
	int status;

	status = event(wd);
	if (status == -1)
		return (-1);
	if (status != 1)
		status = update(wd);
	if (status == -1)
		return (-1);
	status = draw(wd);
	if (status == -1)
		return (-1);
	return (0);
}
