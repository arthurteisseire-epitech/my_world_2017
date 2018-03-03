DSRC	=	./
SRC	=	$(DSRC)my_putchar.c \
		$(DSRC)my_putstr.c \
		$(DSRC)my_puterror.c \
		$(DSRC)my_strlen.c \
		$(DSRC)my_atoi.c \
		$(DSRC)my_strcpy.c \
		$(DSRC)my_strcmp.c \
		$(DSRC)count_words.c \
		$(DSRC)get_next_word.c \
		$(DSRC)in_str.c \
		$(DSRC)len_first_word.c \
		$(DSRC)my_strncpy.c \
		$(DSRC)skip_first_flags.c \
		$(DSRC)split.c \
		$(DSRC)my_itoa.c
OBJ	=	$(SRC:.c=.o)
NAME	=	libmy.a

all: $(NAME)

$(NAME):	$(OBJ)
	cp my.h ../../include
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
	make clean
