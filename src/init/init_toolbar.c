/*
** EPITECH PROJECT, 2017
** File Name : init_toolbar.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my_world.h"
#include "toolbar.h"
#include "init.h"

int init_toolbar(world_t *wd)
{
	wd->toolbar = malloc(sizeof(toolbar_t));
	if (wd->toolbar == NULL)
		return (-1);
	wd->toolbar->pos.x = 20;
	wd->toolbar->pos.y = 20;
	wd->toolbar->offset.x = 15;
	wd->toolbar->offset.y = 15;
	wd->toolbar->tool = malloc(sizeof(tool_t) * NB_TOOLS);
	if (wd->toolbar->tool == NULL)
		return (-1);
	init_tools(wd->toolbar);
	return (0);
}

int init_tools(toolbar_t *toolbar)
{
	tool_t *tool;

	for (int i = 0; i < NB_TOOLS; i++) {
		tool = &toolbar->tool[i];
		tool->rect = sfRectangleShape_create();
		if (tool->rect == NULL)
			return (-1);
		tool->size.x = 120;
		tool->size.y = 120;
		if (i == 0) {
			tool->pos.x = toolbar->pos.x;
			tool->pos.y = toolbar->pos.y;
		} else {
			tool->pos.x = toolbar->tool[i - 1].pos.x + 
					toolbar->offset.x + 
					toolbar->tool[i - 1].size.x;
			tool->pos.y = toolbar->tool[i - 1].pos.y;
		}
		set_rectangle(tool);
	}
	return (0);
}

int set_rectangle(tool_t *tool)
{
	sfRectangleShape_setSize(tool->rect, tool->size);
	sfRectangleShape_setPosition(tool->rect, tool->pos);
	sfRectangleShape_setFillColor(tool->rect, sfRed);
	sfRectangleShape_setOutlineThickness(tool->rect, 2.0);
	sfRectangleShape_setOutlineColor(tool->rect, sfRed);
	return (0);
}
