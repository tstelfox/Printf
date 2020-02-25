# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tmullan <tmullan@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/16 14:03:31 by tmullan        #+#    #+#                 #
#    Updated: 2020/02/25 16:46:06 by tmullan       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

OBJ = ft_printf.o counters.o parsers.o parsers2.o id_arguments.o \
		c_arguments.o x_arguments.o u_arguments.o p_arguments.o \
		s_arguments.o printers.o p_argument2.o printer2.o x_argument2.o \
		pct_argument.o

FLAGS = -Wall -Wextra -Werror

LIB = ./libft

all: complib $(NAME)

complib:
	cd $(LIB) && $(MAKE)

$(NAME): $(OBJ)
	ar rc $@ $^ $(LIB)/*.o
	ranlib $(NAME)

%.o: %.c
	$(CC) -c -o $@ $< $(FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	cd $(LIB) && $(MAKE) fclean

re: fclean all
