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
	sfRectangleShape_setTexture(wd->toolbar->tool[0].rect, wd->textures[0], sfTrue);
}

void set_tool_call(toolbar_t *toolbar)
{
	toolbar->tool[0].call = toggle_raise_mode;
}
