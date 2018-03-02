/*
** EPITECH PROJECT, 2017
** File Name : tool_call.c
** File description:
** by Arthur Teisseire
*/

#include "my_world.h"
#include "toolbar.h"

int toggle_raise_mode(toolbar_t *toolbar)
{
	toolbar->raise_mode = !toolbar->raise_mode;
	return (0);
}
