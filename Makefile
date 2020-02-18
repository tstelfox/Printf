# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tmullan <tmullan@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/16 14:03:31 by tmullan        #+#    #+#                 #
#    Updated: 2020/02/18 17:47:30 by tmullan       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = printf

OBJ = ft_printf.o counters.o parsers.o main_hexa_lower.o id_arguments.o \
		c_arguments.o x_arguments.o u_arguments.o

FLAGS = -Wall -Wextra -Werror

LIB = ./libft

all: complib $(NAME)

complib:
	cd $(LIB) && $(MAKE)

$(NAME): $(OBJ)
	gcc -o $@ $^ $(FLAGS) -L $(LIB) -lft

%.o: %.c
	$(CC) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	cd $(LIB) && $(MAKE) fclean

re: fclean all
