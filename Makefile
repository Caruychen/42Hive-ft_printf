# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 15:25:42 by cchen             #+#    #+#              #
#    Updated: 2022/03/16 09:21:50 by cchen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
EXE := ft_printf

CC := gcc
CFLAGS := -c -Wall -Werror -Wextra
INCLUDES := -I./libft -I./includes

SRC_DIR := ./src
OBJ_DIR := ./obj
SRCS := ./src/$(EXE).c \
	./src/ft_vasprintf.c \
	./src/parse.c \
	./src/parse_conversion.c \
	./src/parse_length.c \
	./src/parse_precision.c \
	./src/parse_flags.c \
	./src/parse_width.c \
	./src/convert_str.c \
	./src/convert_num.c \
	./src/convert_ptr.c \
	./src/convert_dbl.c \
	./src/utils.c \
	./src/modifiers.c \
	./src/mod_flags.c \
	./src/mod_doubles.c \
	./src/rounding.c
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIB_DIR := libft
LIBFT := $(addprefix $(LIB_DIR), libft.a)
LIB_OBJS = $(shell find $(LIB_DIR) -type f | grep -E "\.o$$")

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ_DIR) $(LIBFT) $(OBJS) 
	@ar rcs $(@) $(OBJS) $(LIB_OBJS)

$(OBJ_DIR):
	mkdir -p $(@)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $<

$(LIBFT):
	$(MAKE) -C $(LIB_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	@rm -f $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all
