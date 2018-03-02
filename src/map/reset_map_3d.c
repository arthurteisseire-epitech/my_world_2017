/*
** EPITECH PROJECT, 2017
** File Name : reset_map_3d.c
** File description:
** by Arthur Teisseire
*/

#include "my_world.h"
#include "map.h"

int reset_map_3d(int **map_3d)
{
	for (int row = 0; row < NB_ROW; row++) {
		for (int col = 0; col < NB_COL; col++) {
			map_3d[row][col] = 0;
		}
	}
	return (0);
}
