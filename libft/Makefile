# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/01 15:25:03 by cchen             #+#    #+#              #
#    Updated: 2022/03/15 20:57:17 by cchen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

CC := gcc
CFLAGS := -Wall -Werror -Wextra
INCLUDES := -I./includes -I./includes/libft

SRC_DIR := .
OBJ_DIR := .
SUB_DIR := $(shell find $(SRC_DIR) -type d -mindepth 1 -exec basename {} \;) 
SRCS := ./ft_atoi.c \
	./ft_bzero.c \
	./ft_fmod.c \
	./ft_imax.c \
	./ft_imin.c \
	./ft_isalnum.c \
	./ft_isalpha.c \
	./ft_isascii.c \
	./ft_isdigit.c \
	./ft_islower.c \
	./ft_isprint.c \
	./ft_isupper.c \
	./ft_iswhitespace.c \
	./ft_itoa.c \
	./ft_ldmod.c \
	./ft_lstadd.c \
	./ft_lstdel.c \
	./ft_lstdelone.c \
	./ft_lstiter.c \
	./ft_lstmap.c \
	./ft_lstnew.c \
	./ft_ltoa.c \
	./ft_memalloc.c \
	./ft_memccpy.c \
	./ft_memchr.c \
	./ft_memcmp.c \
	./ft_memcpy.c \
	./ft_memdel.c \
	./ft_memdelarray.c \
	./ft_memmove.c \
	./ft_memset.c \
	./ft_pow.c \
	./ft_putchar.c \
	./ft_putchar_fd.c \
	./ft_putendl.c \
	./ft_putendl_fd.c \
	./ft_putnbr.c \
	./ft_putnbr_fd.c \
	./ft_putstr.c \
	./ft_putstr_fd.c \
	./ft_sqrt.c \
	./ft_strcat.c \
	./ft_strchr.c \
	./ft_strclr.c \
	./ft_strcmp.c \
	./ft_strcpy.c \
	./ft_strdel.c \
	./ft_strdelarray.c \
	./ft_strdup.c \
	./ft_strequ.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlen.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strnequ.c \
	ft_strnew.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strsplit.c \
	ft_strstr.c \
	ft_strsub.c \
	ft_strtrim.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_uitoa.c \
	ft_ultoa.c \
	get_next_line.c \
	vec_append.c \
	vec_append_str.c \
	vec_append_strn.c \
	vec_copy.c \
	vec_free.c \
	vec_from.c \
	vec_new.c \
	vec_push.c \
	vec_resize.c
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

.PHONY: all clean fclean re

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(@)
	mkdir -p $(addprefix $(@)/, $(SUB_DIR))

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	ar -rcs $(NAME) $^

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
