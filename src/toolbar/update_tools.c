/*
** EPITECH PROJECT, 2017
** File Name : update_tools.c
** File description:
** by Arthur Teisseire
*/

#include "my_world.h"
#include "toolbar.h"
#include "stats.h"

int is_tool_clicked(world_t *wd, tool_t *tool)
{
	sfVector2i mouse = sfMouse_getPositionRenderWindow(wd->window);
	int right = tool->pos.x + tool->size.x;
	int bottom = tool->pos.y + tool->size.y;

	if (wd->event.type == sfEvtMouseButtonPressed && 
		(mouse.x > tool->pos.x && mouse.x < right) &&
		(mouse.y > tool->pos.y && mouse.y < bottom))
		return (1);
	return (0);
}

int update_tools(world_t *wd)
{
	tool_t *tool;

	for (int i = 0; i < NB_TOOLS; i++) {
		tool = &wd->toolbar->tool[i];
		if (is_tool_clicked(wd, tool)) {
			if (tool->call(wd) == -1)
				return (-1);
			stats_to_str(wd);
			return (0);
		}
	}
	return (-1);
}
