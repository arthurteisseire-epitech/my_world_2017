/*
** EPITECH PROJECT, 2017
** File Name : toolbar.h
** File description:
** by Arthur Teisseire
*/

#ifndef TOOLBAR_H
#define TOOLBAR_H

#define ABS(x) ((x) < 0 ? -(x) : (x))
#define NB_TOOLS 7
#define TOOL_SIZE 80
#define TOOL_COLOR 160

typedef struct tool tool_t;

typedef struct tool {
	sfVector2f size;
	sfVector2f pos;
	sfRectangleShape *rect;
	sfColor color;
	int (*call)(world_t *wd);
} tool_t;

typedef struct toolbar {
	sfVector2f pos;
	sfVector2f offset;
	tool_t *tool;
} toolbar_t;

int update_tools(world_t *wd);
int update_tool(world_t *wd, tool_t *tool);
int is_tool_clicked(world_t *wd, tool_t *tool);
int is_mouse_on_tool(world_t *wd, tool_t *tool);
int increase_force(world_t *wd);
void set_tool_call(toolbar_t *toolbar);
int toggle_grid(world_t *wd);
int toggle_raise_mode(world_t *wd);
int increase_radius(world_t *wd);
int decrease_radius(world_t *wd);
int decrease_force(world_t *wd);
sfColor new_color(char r, char g, char b, char a);

#endif
