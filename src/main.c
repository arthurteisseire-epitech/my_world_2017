/*
** EPITECH PROJECT, 2017
** File Name : main.c
** File description:
** Ozz
*/
#include "include.h"

int	main()
{
	sfVector2f iso_point;
	int y = 1;

	for (int x = 0; x < 10; x++) {
		iso_point = project_iso_point(x, y, 0);
		printf("%d %d : %f %f\n", x, y, iso_point.x, iso_point.y);
	}
}
