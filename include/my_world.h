/*
** EPITECH PROJECT, 2017
** File Name : my_world.h
** File description:
** Ozz
*/

#ifndef MY_WORLD_H
#define MY_WORLD_H

#include <SFML/Graphics.h>

#define WIDTH 1920
#define HEIGHT 1080
#define TITLE "my_world"
#define NB_COL 6
#define NB_ROW 6
#define NB_TEXTURE 9

typedef struct camera camera_t;
typedef struct toolbar toolbar_t;
typedef struct map map_t;
typedef struct clck clck_t;
typedef struct text text_t;
typedef struct stats stats_t;

typedef struct world {
	camera_t *cam;
	sfEvent event;
	sfRenderWindow *window;
	sfTexture **textures;
	toolbar_t *toolbar;
	map_t *map;
	stats_t *stats;
	sfSprite *background;
	int nb_row;
	int nb_col;
	char *pathname;
} world_t;

int run(char *pathname);
int check_env(char **env);
int check_env_var(char *env_var);
int len_tokens(char **tokens);
void free_tokens(char **tokens);

#endif
