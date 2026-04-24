# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/24 13:23:28 by alubrano          #+#    #+#              #
#    Updated: 2026/04/24 13:42:58 by alubrano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
GREEN	= \033[0;32m
RED		= \033[0;31m
RESET	= \033[0m

# Project
NAME	= cub3D
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g

SRC_DIR	= src
OBJ_DIR	= obj
INC_DIR	= includes

SRC		=


SRCS	= $(addprefix $(SRC_DIR)/, $(SRC))
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Libft
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

# MiniLibX
MLX_DIR		= minilibx-linux
MLX_LIB		= $(MLX_DIR)/libmlx.a
MLX_INC		= -I$(MLX_DIR)
MLX_LDFLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11

INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR) $(MLX_INC)

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(MLX_LIB) $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft $(MLX_LDFLAGS) -o $(NAME)
	@echo "$(GREEN)✓ Build OK: $(NAME)$(RESET)"

valgrind1:
	@valgrind --leak-check=full ./cub3D ./maps/valid/42.cub

map1:
	@./cub3D ./maps/valid/42.cub

map2:
	@./cub3D ./maps/invalid/impossible.cub

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@echo "$(RED)✗ Objects removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(RED)✗ $(NAME) removed$(RESET)"

re: fclean all

.PHONY: all valgrind1 map1 map2 clean fclean re