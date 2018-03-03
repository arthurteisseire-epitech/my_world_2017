/*
** EPITECH PROJECT, 2017
** File Name : stats.h
** File description:
** by Arthur Teisseire
*/

#ifndef STATS_H
#define STATS_H

typedef struct text text_t;

typedef struct stats {
	int raise_mode;
	int increasing;
	int radius;
	int force;
	text_t *text;
} stats_t;

void stats_to_str(world_t *wd);

#endif
