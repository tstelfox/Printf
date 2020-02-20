# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tmullan <tmullan@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/16 14:03:31 by tmullan        #+#    #+#                 #
#    Updated: 2020/02/20 20:41:15 by tmullan       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = printf

OBJ = ft_printf.o counters.o parsers.o id_arguments.o \
		c_arguments.o x_arguments.o u_arguments.o p_arguments.o \
		s_arguments.o printers.o p_argument2.o printer2.o x_argument2.o

FLAGS = -Wall -Wextra -Werror

LIB = ./libft

all: complib $(NAME)

complib:
	cd $(LIB) && $(MAKE)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(FLAGS) -L $(LIB) -lft $(FLAGS)

%.o: %.c
	$(CC) -c -o $@ $< $(FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	cd $(LIB) && $(MAKE) fclean

re: fclean all
