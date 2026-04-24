# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/04 22:20:16 by alubrano          #+#    #+#              #
#    Updated: 2026/02/26 11:39:22 by alubrano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
GREEN = \033[0;32m
CYAN = \033[0;36m
RED = \033[0;31m
YELLOW = \033[0;33m
RESET = \033[0m

SRC_DIR = src
OBJ_DIR = obj

LIBC =	ft_atoi.c		ft_bzero.c		ft_calloc.c		ft_isalnum.c	ft_isalpha.c\
		ft_isascii.c	ft_isdigit.c	ft_isprint.c	ft_memchr.c\
		ft_memcmp.c		ft_memcpy.c		ft_memmove.c	ft_memset.c		ft_strchr.c\
		ft_strdup.c		ft_strlcat.c	ft_strlcpy.c	ft_strlen.c		ft_strncmp.c\
		ft_strnstr.c	ft_strrchr.c	ft_tolower.c	ft_toupper.c	ft_lstnew.c\
		ft_lstadd_front.c				ft_lstsize.c	ft_lstlast.c	ft_lstadd_back.c\
		ft_lstdelone.c	ft_lstclear.c	ft_lstiter.c	ft_lstmap.c		ft_itoa.c\
		ft_putchar_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c	ft_putstr_fd.c	ft_split.c\
		ft_strjoin.c	ft_strmapi.c	ft_strtrim.c	ft_substr.c		ft_striteri.c\
		ft_ll_putnbr.c	ft_putnbr_base.c				ft_int_putptr.c		ft_ll_itoa.c\
		ft_printf.c		ft_int_putptr.c	get_next_line.c	ft_strcmp.c


FLAGS = -Wall -Werror -Wextra -I.

SRC = $(LIBC)

SRCALL = $(LIBC)

SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
SRCS_ALL = $(addprefix $(SRC_DIR)/, $(SRCALL))

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJALL = $(addprefix $(OBJ_DIR)/, $(SRCALL:.c=.o))

TOTAL = $(words $(SRC))
COMPILED = 0

NAME = libft.a

CC = gcc


all : $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(FLAGS) -o $@ -c $< 2>/dev/null

$(NAME) : $(OBJ)
	@echo "$(GREEN)✓ Compilation done! [$(TOTAL) files]$(RESET)"
	@ar rcs $(NAME) $(OBJ)
	@echo "$(GREEN)✓ $(NAME) created successfully!$(RESET)"

bonus : $(OBJALL)
	@ar rcs $(NAME) $(OBJALL)
	@echo "$(GREEN)✓ $(NAME) with bonus created!$(RESET)"

clean :
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)✗ Object files removed$(RESET)"

fclean : clean
	@rm -f $(NAME)
	@echo "$(RED)✗ $(NAME) removed$(RESET)"

re : fclean all

.PHONY : all clean fclean re bonus
