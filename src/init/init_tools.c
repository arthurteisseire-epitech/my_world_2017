/*
** EPITECH PROJECT, 2017
** File Name : init_tools.c
** File description:
** by Arthur Teisseire
*/

#include "my_world.h"
#include "toolbar.h"
#include "save.h"

void set_tool_image(world_t *wd)
{
	sfRectangleShape_setTexture(wd->toolbar->tool[0].rect, wd->textures[2], sfFalse);
	sfRectangleShape_setTexture(wd->toolbar->tool[1].rect, wd->textures[3], sfFalse);
	sfRectangleShape_setTexture(wd->toolbar->tool[2].rect, wd->textures[4], sfFalse);
	sfRectangleShape_setTexture(wd->toolbar->tool[3].rect, wd->textures[5], sfFalse);
	sfRectangleShape_setTexture(wd->toolbar->tool[4].rect, wd->textures[6], sfFalse);
	sfRectangleShape_setTexture(wd->toolbar->tool[5].rect, wd->textures[7], sfFalse);
	sfRectangleShape_setTexture(wd->toolbar->tool[6].rect, wd->textures[8], sfFalse);
}

void set_tool_call(toolbar_t *toolbar)
{
	toolbar->tool[0].call = toggle_raise_mode;
	toolbar->tool[1].call = toggle_grid;
	toolbar->tool[2].call = decrease_radius;
	toolbar->tool[3].call = increase_radius;
	toolbar->tool[4].call = decrease_force;
	toolbar->tool[5].call = increase_force;
	toolbar->tool[6].call = save_map;
}
