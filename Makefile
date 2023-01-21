NAME := fract-ol

# Directories
INC_DIR := includes
OBJ_DIR := obj
SRC_DIR := src
MLX_DIR := $(INC_DIR)/MLX42

# Compiler flags
CC := gcc
INCL_WINDOWS := -ldl -lglfw -pthread -lm
INCL := -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
CFLAGS := -Wall -Werror -Wextra -o3

# files
SRC_FILES :=	fractol.c		\
				fractals.c		\
				fractol_utils.c

SRC := $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ := ${addprefix ${OBJ_DIR}/, ${SRC_FILES:.c=.o}}
MLX := $(MLX_DIR)/libmlx42.a

# Colours
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
RED		:= \033[31;1m
BOLD	:= \033[1m
RESET	:= \033[0m

# Rules
all: ${NAME}

$(NAME): $(MLX) $(OBJ)
	@echo "$(YELLOW)$(BOLD)Compiling FRACT-OL...$(RESET)"
	@gcc $(OBJ) $(CFLAGS) $(MLX) $(INCL_WINDOWS) -o $(NAME)
	@echo "$(GREEN)$(BOLD)FRACT-OL Compiled$(RESET)"

$(MLX):
	@echo "$(YELLOW)$(BOLD)Compiling MLX42...$(RESET)"
	@$(MAKE) -s -C $(MLX_DIR)
	@echo "$(GREEN)$(BOLD)MLX42 Compiled$(RESET)"

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p obj
	@gcc $(CFLAGS) -I $(INC_DIR) -c $< -o $@

open: $(NAME)
	@echo "$(YELLOW)$(BOLD)Opening window...$(RESET)"
	@echo -n "$(RED)"
	@./$(NAME) 1
	@echo "$(GREEN)$(BOLD)Window closed$(RESET)"

norminette:
	@norminette $(SRC)

clean:
	@echo "$(RED)$(BOLD)Cleaning...$(RESET)"
	@$(MAKE) clean -sC $(MLX_DIR)
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -sC $(MLX_DIR)
	@rm -rf ${NAME}

re: fclean ${NAME}

.PHONY: all open norminette clean fclean re 
