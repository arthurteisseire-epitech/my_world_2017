/*
** EPITECH PROJECT, 2017
** File Name : toolbar.h
** File description:
** by Arthur Teisseire
*/

#ifndef TOOLBAR_H
#define TOOLBAR_H

#define NB_TOOLS 3

typedef struct tool {
	sfVector2f size;
	sfVector2f pos;
	sfRectangleShape *rect;
} tool_t;

typedef struct toolbar {
	sfVector2f pos;
	sfVector2f offset;
	tool_t *tool;
	char tile_mode;
	char increasing;
} toolbar_t;

#endif
