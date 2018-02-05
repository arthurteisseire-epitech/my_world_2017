/*
** EPITECH PROJECT, 2017
** File Name : main.c
** File description:
** By Arthur Teisseire
*/

#include "my_world.h"
#include "states.h"
#include "init.h"

int main(void)
{
	world_t wd;

	init_world(&wd);
	while (sfRenderWindow_isOpen(wd.window)) {
		event(&wd);
		update(&wd);
		draw(&wd);
	}
	destroy(&wd);
	return (0);
}
