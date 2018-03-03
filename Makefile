##
## EPITECH PROJECT, 2017
## Makefile
## File description:
##  Ozz
##

CC	=	gcc
DSRC	=	src/
DINIT	=	$(DSRC)init/
DSTATE	=	$(DSRC)states/
DMAP	=	$(DSRC)map/
DESTROY	=	$(DSRC)destroy/
DINPUT	=	$(DSRC)input/
DTOOL	=	$(DSRC)toolbar/
DTEXT	=	$(DSRC)text/

SRC	=	$(DSRC)main.c \
		$(DSRC)game_loop.c \
		$(DSRC)check_env.c \
		$(DMAP)iso.c \
		$(DMAP)set_map.c \
		$(DMAP)draw_map.c \
		$(DMAP)shadow_tiles.c \
		$(DMAP)tile.c \
		$(DMAP)reset_map_3d.c \
		$(DTOOL)tool_call.c \
		$(DTOOL)update_tools.c \
		$(DINIT)init_world.c \
		$(DINIT)init_toolbar.c \
		$(DINIT)init_map.c \
		$(DINIT)init_tiles.c \
		$(DINIT)init_camera.c \
		$(DINIT)init_textures.c \
		$(DINIT)init_tools.c \
		$(DINIT)init_stats.c \
		$(DINPUT)move_map.c \
		$(DINPUT)click.c \
		$(DINPUT)raise_points.c \
		$(DSTATE)event.c \
		$(DSTATE)update.c \
		$(DSTATE)draw.c \
		$(DSTATE)states.c \
		$(DTEXT)disp_stats.c \
		$(DESTROY)destroy.c \
		$(DESTROY)free_stats.c \
		$(DESTROY)free_tiles.c

OBJ	=	$(SRC:.c=.o)
INC	=	include/
DLIB	=	lib/my/
LIB	=	my
LIBS	=	-L$(DLIB) -l$(LIB)
NAME	=	my_world
LDFLAGS	=	-lc_graph_prog -lm
CFLAGS	+=	-Wall -W -Wextra -I $(INC) -g

all: $(NAME)

$(NAME):	$(OBJ)
	make -C $(DLIB)
	$(CC) -o $(NAME) $(OBJ) $(LIBS) $(LDFLAGS) 

clean:
	make clean -C $(DLIB)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(DLIB)
	rm -f $(NAME)

re:	fclean all
	make clean
