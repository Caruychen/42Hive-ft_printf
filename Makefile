# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 15:25:42 by cchen             #+#    #+#              #
#    Updated: 2022/02/15 19:50:54 by cchen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
EXE := ft_printf

CC := gcc
CFLAGS := -c -Wall -Werror -Wextra
INCLUDES := -I./libft -I./includes

SRC_DIR := ./src
OBJ_DIR := ./obj
SRCS := ./src/$(EXE).c
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
HEADER := $(SRC_DIR)/$(EXE).h

LIB_DIR := libft
LIBFT := $(addprefix $(LIB_DIR), libft.a)
LIB_OBJS := $(shell find $(LIB_DIR) -type f | grep -E "\.o$$")

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT)
	ar rcs $@ $(OBJS) $(LIB_OBJS)

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
