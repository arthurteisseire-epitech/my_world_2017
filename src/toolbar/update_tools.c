/*
** EPITECH PROJECT, 2017
** File Name : update_tools.c
** File description:
** by Arthur Teisseire
*/

#include "my_world.h"
#include "toolbar.h"

int is_tool_clicked(sfEvent *event, tool_t *tool)
{
	int right = tool->pos.x + tool->size.x;
	int bottom = tool->pos.y + tool->size.y;

	if (event->mouseButton.x > tool->pos.x && 
		event->mouseButton.x < right &&
		event->mouseButton.y > tool->pos.y &&
		event->mouseButton.y < bottom)
		return (1);
	return (0);
}

int update_tools(world_t *wd)
{
	tool_t *tool;

	for (int i = 0; i < NB_TOOLS; i++) {
		tool = &wd->toolbar->tool[i];
		if (is_tool_clicked(&wd->event, tool)) {
			tool->call(wd->toolbar);
			return (0);
		}
	}
	return (-1);
}
