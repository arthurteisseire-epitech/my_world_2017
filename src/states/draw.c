/*
** EPITECH PROJECT, 2017
** File Name : disp.c
** File description:
** By Arthur Teisseire
*/

#include <stdlib.h>
#include "my_world.h"
#include "map.h"
#include "toolbar.h"
#include "states.h"
#include "stats.h"
#include "text.h"

int draw(world_t *wd)
{
	sfRenderWindow_clear(wd->window, sfBlack);
	sfRenderWindow_drawSprite(wd->window, wd->background, NULL);
	draw_map(wd);
	toolbar_disp(wd);
	sfRenderWindow_drawText(wd->window, wd->stats->text->text, NULL);
	sfRenderWindow_display(wd->window);
	return (0);
}

int toolbar_disp(world_t *wd)
{
	for (int i = 0; i < NB_TOOLS; i++)
		sfRenderWindow_drawRectangleShape(
			wd->window,
			wd->toolbar->tool[i].rect,
			NULL);
	return (0);
}
