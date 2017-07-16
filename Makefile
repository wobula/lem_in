# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rschramm <rschramm@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/10 14:23:11 by rschramm          #+#    #+#              #
#    Updated: 2017/05/30 17:35:26 by rschramm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = lem-in

CC = gcc

FLAG += -Wall -Werror -Wextra

SRC = ./srcs/main.c \
		./srcs/free_all.c \
		./srcs/validate_input.c \
		./srcs/solve.c \
		./srcs/add_doors_to_rooms.c \
		./srcs/create_solution_path.c \
		./srcs/check_for_end.c \
		./srcs/get_input.c \
		./srcs/add_room.c \
		./srcs/add_link.c \
		./srcs/display_room_links.c \
		./srcs/part_of_path.c \
		./srcs/get_ants.c \
		./srcs/display_rooms.c \
	  
OBJ = $(SRC:.c=.o)

LIBFT = libft/libftprintf.a \

all: $(NAME)

$(NAME): $(OBJ)
	@make re -C libft
	@gcc $(FLAG) -o $(NAME) $(SRC) $(LIBFT)
	@echo "\033[33;32mSystem Ready >:D"

clean:
	@make clean -C libft
	@rm -f $(OBJ)
	@echo "\033[33mCleaned..."

fclean:
	@make clean
	@make fclean -C libft
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@echo "\033[31mfCleaned..."

re: fclean all
