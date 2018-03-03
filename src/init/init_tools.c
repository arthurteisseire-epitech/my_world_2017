/*
** EPITECH PROJECT, 2017
** File Name : init_tools.c
** File description:
** by Arthur Teisseire
*/

#include "my_world.h"
#include "toolbar.h"

void set_tool_image(world_t *wd)
{
	sfRectangleShape_setTexture(wd->toolbar->tool[0].rect, wd->textures[0], sfFalse);
	sfRectangleShape_setTexture(wd->toolbar->tool[1].rect, wd->textures[1], sfFalse);
	sfRectangleShape_setTexture(wd->toolbar->tool[2].rect, wd->textures[2], sfFalse);
	sfRectangleShape_setTexture(wd->toolbar->tool[3].rect, wd->textures[2], sfFalse);
}

void set_tool_call(toolbar_t *toolbar)
{
	toolbar->tool[0].call = toggle_raise_mode;
	toolbar->tool[1].call = toggle_grid;
	toolbar->tool[2].call = increase_radius;
	toolbar->tool[3].call = decrease_radius;
}
