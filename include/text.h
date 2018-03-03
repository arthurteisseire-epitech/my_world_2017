/*
** EPITECH PROJECT, 2017
** File Name : text.h
** File description:
** by Arthur Teisseire
*/

#ifndef TEXT_H
#define TEXT_H

typedef struct text {
	sfText *text;
	sfFont *font;
	char str[128];
} text_t;

void set_style(world_t *wd);

#endif
