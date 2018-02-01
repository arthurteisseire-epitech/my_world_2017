/*
** EPITECH PROJECT, 2017
** File Name : main.c
** File dewdription:
** By Arthur Teisseire
*/

#include "my_world.h"
#include "world_struct.h"
#include "states.h"

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
