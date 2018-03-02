/*
** EPITECH PROJECT, 2017
** File Name : toolbar.h
** File description:
** by Arthur Teisseire
*/

#ifndef TOOLBAR_H
#define TOOLBAR_H

#define ABS(x) ((x) < 0 ? -(x) : (x))
#define NB_TOOLS 1

typedef struct tool tool_t;

typedef struct tool {
	sfVector2f size;
	sfVector2f pos;
	sfRectangleShape *rect;
	int (*call)(toolbar_t *toolbar);
} tool_t;

typedef struct toolbar {
	sfVector2f pos;
	sfVector2f offset;
	tool_t *tool;
	char raise_mode;
	char increasing;
	int radius;
	int force;
} toolbar_t;

int toggle_raise_mode(toolbar_t *toolbar);
int update_tools(world_t *wd);
int is_tool_clicked(world_t *wd, tool_t *tool);
void set_tool_call(toolbar_t *toolbar);

#endif
