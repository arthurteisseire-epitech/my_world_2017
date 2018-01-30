/*
** EPITECH PROJECT, 2017
** File Name : main.c
** File description:
** By Arthur Teisseire
*/

#include "my_world.h"
#include "screen.h"
#include "states.h"

int main(void)
{
	screen_t sc;

	init_screen(&sc);      
	while (sfRenderWindow_isOpen(sc.window)) {
		event(&sc);
		update(&sc);
		draw(&sc);
	}
	destroy(&sc);
	return (0);
}
