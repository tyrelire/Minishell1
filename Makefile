##
## EPITECH PROJECT, 2022
## my_bsq.c
## File description:
## my_bsq
##

SRC		=	src/main.c \
			src/execve.c \
			src/my_getpath.c \
			src/my_command.c \
			src/my_cd_path.c \
			src/signal.c \
			src/misc.c \
			lib/my_putstr_err.c \
			lib/my_str_cut.c \
			lib/my_strdup.c \
			lib/my_fastput_array.c \
			lib/my_fast_putstr.c \
			lib/my_strlen.c \
			lib/binaire.c \
			lib/decimal_to_octal.c \
			lib/into_hex_max.c \
			lib/my_strcpy.c \
			lib/my_strcat.c \
			lib/into_hex_min.c \
			lib/my_put_nbr.c \
			lib/my_putchar.c \
			lib/my_get_nbr.c \
			lib/my_putstr.c \
			lib/my_strncmp.c \
			lib/non_sign.c \
			lib/nprintable_char.c \
			lib/my_str_to_word_array.c \
			lib/my_str_to_word_array_point.c \
			lib/my_str_to_word_array_space.c \
			lib/my_printf.c \
			lib/my_put_tab.c

OBJ		=	$(SRC:.c=.o)

NAME	=	mysh

all	:	$(NAME)

$(NAME)	:
	gcc $(SRC) -W -Wall -I include -o $(NAME) -g3

clean	:
	rm -f $(OBJ)

fclean	:	clean
	rm -f $(NAME)

re	    :	fclean all
