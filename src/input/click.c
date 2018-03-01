/*
** EPITECH PROJECT, 2017
** File Name : click.c
** File description:
** Ozz
*/

#include "my_world.h"
#include "input.h"
#include "camera.h"
#include "map.h"

#define RADIUS 15
/*
int is_mouse_in_tile(map_t *map, sfVector2i pos)
{
	return (0);
}
*/
void raise(map_t *map, sfVector2i pt, int nb_pt)
{
	//printf("RAISE X:%d Y:%d\n", x, y);
	/* for (int i = 0; i < nb_pt; i++) {
	   map->map_3d[pts[i].x][pts[i].y]--;
	   }
	   */
	(void)nb_pt;
	map->map_3d[pt.x][pt.y]--;
}

void detect_point(map_t *map, sfVector2i pt, sfVector2i pos)
{
	int map_x = map->map_2d[pt.x][pt.y].x;
	int map_y = map->map_2d[pt.x][pt.y].y;
	int mouse_x = pos.x;
	int mouse_y = pos.y;

	//printf("MOUSE X:%d Y:%d\n", pos.x, pos.y);
	//printf("MAP X:%d Y:%d\n", map_x, map_y);
	if (map_x - RADIUS < mouse_x && mouse_x < map_x + RADIUS) {
		if (map_y - RADIUS < mouse_y && mouse_y < map_y + RADIUS) {
			raise(map, pt, 1);
		}
	}
}

int check_map_2d(map_t *map, sfVector2i pos)
{
	sfVector2i pt;
	pt.x = NB_COL;

	while (pt.x > 0) {
		pt.x--;
		pt.y = NB_ROW;
		while (pt.y > 0) {
			pt.y--;
			detect_point(map, pt, pos);
		}
	}
	return (0);
}
