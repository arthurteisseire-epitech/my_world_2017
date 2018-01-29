/*
** EPITECH PROJECT, 2017
** File Name : screen.h
** File description:
** by Arthur Teisseire
*/

#ifndef SCREEN_H
#define SCREEN_H

#include <SFML/Graphics.h>

typedef struct screen {
	sfEvent event;
	sfRenderWindow *window;
} screen_t;

void init_screen(screen_t *sc);
sfRenderWindow *create_window(void);

#endif