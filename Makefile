##
## EPITECH PROJECT, 2017
## Makefile
## File description:
##  Ozz
##

CC	=	gcc
DSRC	=	$(realpath ./src)/
DINIT	=	$(DSRC)init/
DSTATE	=	$(DSRC)states/
DMAP	=	$(DSRC)map/
DESTROY	=	$(DSRC)destroy/
DINPUT	=	$(DSRC)input/
SRC	=	$(DSRC)main.c \
		$(DSRC)game_loop.c \
		$(DMAP)iso.c \
		$(DMAP)set_map.c \
		$(DMAP)draw_map.c \
		$(DINIT)init_world.c \
		$(DINIT)init_toolbar.c \
		$(DINIT)init_map.c \
		$(DINIT)init_tiles.c \
		$(DINIT)init_camera.c \
		$(DINIT)init_textures.c \
		$(DINPUT)move_map.c \
		$(DINPUT)click.c \
		$(DSTATE)event.c \
		$(DSTATE)update.c \
		$(DSTATE)draw.c \
		$(DESTROY)destroy.c \
		$(DESTROY)free_tiles.c
OBJ	=	$(SRC:.c=.o)
INC	=	$(realpath ./include)/
DLIB	=	$(realpath lib)
LIB	=	my
LIBS	=	-L$(DLIB) -l$(LIB)
NAME	=	my_world
LDFLAGS	=	-lc_graph_prog -lm
CFLAGS	+=	-Wall -W -Wextra -I $(INC) -g

all: $(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBS) $(LDFLAGS) 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
	make clean
