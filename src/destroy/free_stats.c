/*
** EPITECH PROJECT, 2017
** File Name : free_stats.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my_world.h"
#include "stats.h"
#include "text.h"

int free_stats(stats_t *stats)
{
	sfText_destroy(stats->text->text);
	sfFont_destroy(stats->text->font);
	free(stats->text);
	free(stats);
	return (0);
}
