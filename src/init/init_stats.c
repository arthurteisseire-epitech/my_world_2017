/*
** EPITECH PROJECT, 2017
** File Name : init_stats.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my_world.h"
#include "stats.h"
#include "text.h"

int init_stats(world_t *wd)
{
	wd->stats = malloc(sizeof(stats_t));
	if (wd->stats == NULL)
		return (-1);
	wd->stats->text = malloc(sizeof(text_t));
	if (wd->stats->text == NULL)
		return (-1);
	wd->stats->text->text = sfText_create();
	if (wd->stats->text->text == NULL)
		return (-1);
	wd->stats->text->font = sfFont_createFromFile("assets/Square.ttf");
	if (wd->stats->text->font == NULL)
		return (-1);
	wd->stats->raise_mode = 1;
	wd->stats->increasing = 1;
	wd->stats->radius = 1;
	wd->stats->force = 1;
	set_style(wd);
	stats_to_str(wd);
	if (wd->stats->text->str == NULL)
		return (-1);
	return (0);
}

void set_style(world_t *wd)
{
	sfVector2f pos = {20, HEIGHT - 120};

	sfText_setFont(wd->stats->text->text, wd->stats->text->font);
	sfText_setCharacterSize(wd->stats->text->text, 30);
	sfText_setColor(wd->stats->text->text, sfWhite);
	sfText_setPosition(wd->stats->text->text, pos);
}
