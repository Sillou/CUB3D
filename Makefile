# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/24 13:23:28 by alubrano          #+#    #+#              #
#    Updated: 2026/05/04 14:38:30 by alubrano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
GREEN	= \033[0;32m
RED		= \033[0;31m
YELLOW	= \033[0;33m
RESET	= \033[0m

#Standard

NAME		= cub3D
INC_DIR		= 01_includes
LIBFT_DIR	= libft
SRCS_DIR 	= ./
OBJS_DIR 	= obj/
CC 			= gcc-11
RM 			= rm -f
CFLAGS 		= -Wall -Wextra -Werror -g -I/usr/include/X11

# Libft
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

#MinilibX

MLX_DIR		= minilibx-linux
MLX_LIB		= $(MLX_DIR)/libmlx.a
MLX_INC		= -I$(MLX_DIR)
MLX_LDFLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm


#Sources

MAIN = 00_src/main

PARSING = 00_src/00_parsing/
PARS =	check_args check_map parse_map parse_texture parse_color parse_utils\
		check_valid_map	check_valid_map2

INIT = 00_src/01_init/
INI = init_to_start	init_mlx	init_map_2D

RAYCASTING = 00_src/02_raycasting/
RAYCAST = init_raycast	raycast

MOVEMENTS = 00_src/03_movements/
MOVES = moves

EXIT = 00_src/04_exit/
EXT =	close free_mem

SRC_FILES += $(MAIN)
SRC_FILES += $(addprefix $(PARSING),$(PARS))
SRC_FILES += $(addprefix $(INIT),$(INI))
SRC_FILES += $(addprefix $(RAYCASTING),$(RAYCAST))
SRC_FILES += $(addprefix $(MOVEMENTS),$(MOVES))
SRC_FILES += $(addprefix $(EXIT),$(EXT))


SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

###

OBJSF 		= .cache_exists
INCLUDES 	= -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

all: ${NAME}

bonus: $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) -D BONUS=1 $(OBJS) $(LIBFT) -lreadline -o $(NAME)
	@echo "$(GREEN)✓ Build OK: libft$(RESET)"
	@echo "$(GREEN)✓ Build OK: bonus $(NAME)$(RESET)"

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLX_LIB):
	@make -C $(MLX_DIR) CC=gcc-11


$(NAME): $(MLX_LIB) $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(MLX_LIB) -lXext -lX11 -lm -o $(NAME)
	@echo "$(GREEN)✓ Build OK: libft$(RESET)"
	@echo "$(GREEN)✓ Build OK: $(NAME)$(RESET)"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c | $(OBJSF)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJSF):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)$(PARSING)
	@mkdir -p $(OBJS_DIR)$(INIT)
	@mkdir -p $(OBJS_DIR)$(RAYCASTING)
	@mkdir -p $(OBJS_DIR)$(MOVEMENTS)
	@mkdir -p $(OBJS_DIR)$(EXIT)
	@mkdir -p $(OBJS_DIR)00_src/01_init
	@mkdir -p $(OBJS_DIR)00_src/00_parsing
	@mkdir -p $(OBJS_DIR)00_src/02_raycasting
	@mkdir -p $(OBJS_DIR)00_src/03_movements
	@mkdir -p $(OBJS_DIR)00_src/04_exit

clean:
	@$(RM) -rf $(OBJS_DIR)
	@$(RM) -f $(OBJSF)
	@echo "$(RED)✗ Objects removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)✗ $(NAME) removed$(RESET)"

re: fclean all

valgrind: all
	@echo "$(YELLOW)🔍 Running valgrind...$(RESET)"
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "$(ARGS)"

.PHONY : all clean fclean re valgrind
