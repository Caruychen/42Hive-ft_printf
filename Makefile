# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 15:25:42 by cchen             #+#    #+#              #
#    Updated: 2022/02/15 16:14:50 by cchen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
EXE := ft_printf

CC := gcc
CFLAGS := -c -Wall -Werror -Wextra
INCLUDES := -I./libft -I./includes

HEADER := $(SRC_DIR)/$(EXE).h
SRC_DIR := src
OBJ_DIR := obj
SRCS := ./src/$(EXE).c
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT := libft

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT)
	ar rcs $@ $^

$(OBJ_DIR):
	mkdir -p $(@)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $<

$(LIBFT):
	$(MAKE) -C $(LIBFT)

clean:
	@rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT) clean

fclean: clean
	@rm -f $(
