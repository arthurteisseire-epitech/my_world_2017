/*
** EPITECH PROJECT, 2017
** File Name : update_tools.c
** File description:
** by Arthur Teisseire
*/

#include "my_world.h"
#include "toolbar.h"
#include "stats.h"

int update_tools(world_t *wd)
{
	int status;

	for (int i = 0; i < NB_TOOLS; i++) {
		status = update_tool(wd, &wd->toolbar->tool[i]);
		if (status == -1)
			return (-1);
		else if (status == 1)
			return (0);
	}
	return (-1);
}

int update_tool(world_t *wd, tool_t *tool)
{
	sfColor color;

	if (is_tool_clicked(wd, tool)) {
		if (tool->call(wd) == -1)
			return (-1);
		stats_to_str(wd);
		return (1);
	} else if (is_mouse_on_tool(wd, tool)) {
		color = new_color(120, 120, 120, 255);
		sfRectangleShape_setOutlineThickness(tool->rect, 2.5);
		sfRectangleShape_setFillColor(tool->rect, color);
	} else {
		color = new_color(TOOL_COLOR, TOOL_COLOR, TOOL_COLOR, 255);
		sfRectangleShape_setOutlineThickness(tool->rect, 1.0);
		sfRectangleShape_setFillColor(tool->rect, color);
	}
	return (0);
}

int is_tool_clicked(world_t *wd, tool_t *tool)
{
	if (wd->event.type == sfEvtMouseButtonPressed && 
	is_mouse_on_tool(wd, tool))
		return (1);
	return (0);
}

int is_mouse_on_tool(world_t *wd, tool_t *tool)
{
	sfVector2i mouse = sfMouse_getPositionRenderWindow(wd->window);
	int right = tool->pos.x + tool->size.x;
	int bottom = tool->pos.y + tool->size.y;

	if ((mouse.x > tool->pos.x && mouse.x < right) &&
	(mouse.y > tool->pos.y && mouse.y < bottom))
		return (1);
	return (0);
}
