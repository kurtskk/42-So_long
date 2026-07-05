# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kgagliar <kgagliar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/07 16:04:52 by kgagliar          #+#    #+#              #
#    Updated: 2025/09/07 16:04:52 by kgagliar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long
BONUS_NAME		= so_long_bonus
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

SRC_DIR			= src
BONUS_DIR		= bonus/src
LIBFT_DIR		= lib/libft
MLX_DIR			= minilibx-linux

LIBFT			= $(LIBFT_DIR)/libft.a
MLX_LIB			= $(MLX_DIR)/libmlx.a
MLX_FLAGS		= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
INCLUDES		= -I./ -I$(LIBFT_DIR) -I$(MLX_DIR)

SRCS = $(SRC_DIR)/so_long.c \
       $(SRC_DIR)/movements.c \
       $(SRC_DIR)/read_map.c \
       $(SRC_DIR)/draw_map.c \
       $(SRC_DIR)/sprites.c \
       $(SRC_DIR)/player_moves.c \
       $(SRC_DIR)/keyhook.c \
       $(SRC_DIR)/ft_free.c \
       $(SRC_DIR)/utils.c \
       $(SRC_DIR)/file_to_image.c \
       $(SRC_DIR)/valid_path.c \
       $(SRC_DIR)/valid_map.c

BONUS_SRCS = $(BONUS_DIR)/so_long_bonus.c \
             $(BONUS_DIR)/close_game_bonus.c \
             $(BONUS_DIR)/draw_map_bonus.c \
             $(BONUS_DIR)/enemies_bonus.c \
             $(BONUS_DIR)/file_to_image_bonus.c \
             $(BONUS_DIR)/free_game_bonus.c \
             $(BONUS_DIR)/keyhook_bonus.c \
             $(BONUS_DIR)/move_enemy_bonus.c \
             $(BONUS_DIR)/movements_bonus.c \
             $(BONUS_DIR)/player_moves_bonus.c \
             $(BONUS_DIR)/read_map_bonus.c \
             $(BONUS_DIR)/sprites_bonus.c \
             $(BONUS_DIR)/utils_bonus.c \
             $(BONUS_DIR)/valid_map_bonus.c \
             $(BONUS_DIR)/valid_path_bonus.c

OBJS		= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

all: $(LIBFT) $(MLX_LIB) $(NAME)

bonus: $(LIBFT) $(MLX_LIB) $(BONUS_NAME)

$(LIBFT):
	@echo "\033[0;32mCompilando libft...\033[0m"
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	@echo "\033[0;32mCompilando MiniLibX...\033[0m"
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(MLX_LIB)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) $(INCLUDES) -o $(NAME)
	@echo "\033[1;32m✓ Compilado com sucesso: $(NAME)\033[0m"

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT) $(MLX_LIB)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) $(MLX_FLAGS) $(INCLUDES) -o $(BONUS_NAME)
	@echo "\033[1;36m✓ Compilado com sucesso: $(BONUS_NAME)\033[0m"

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BONUS_DIR)/%.o: $(BONUS_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS) $(BONUS_OBJS)
	@echo "\033[0;33mObjetos removidos!\033[0m"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME) $(BONUS_NAME)
	@echo "\033[0;31mTudo removido!\033[0m"

re: fclean all

.PHONY: all bonus clean fclean re