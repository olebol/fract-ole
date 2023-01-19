NAME := fract-ol

# Compiler parts
CC := gcc
INCL := -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
CFLAGS := -Wall -Werror -Wextra -o3

SRC :=	fractol.c		\
		fractals.c

MLX := libmlx42.a

# Colours
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
RED		:= \033[31;1m
BOLD	:= \033[1m
RESET	:= \033[0m

# Rules
all: ${NAME}

${NAME}: $(MLX) $(SRC)
	@gcc $(SRC) $(CFLAGS) $(MLX) $(HEADER) $(INCL) -o $(NAME)
	@echo "$(GREEN)$(BOLD)FRACT-OL Compiled$(RESET)"

open: $(NAME)
	@echo "$(YELLOW)$(BOLD)Opening window...$(RESET)"
	@./$(NAME)
	@echo "$(GREEN)$(BOLD)Window closed$(RESET)"

# Makes libmlx42.a
$(MLX):
	@$(MAKE) -C MLX42/
	@mv ./MLX42/$(MLX) .
	@echo "$(GREEN)$(BOLD)MLX42 Compiled$(RESET)"

norminette:
	@norminette $(SRC)

clean:
	@echo "$(RED)$(BOLD)Cleaning...$(RESET)"
	@rm -rf ${NAME}

fclean: clean
	@rm -rf $(MLX)

re: fclean ${NAME}

.PHONY: all norminette clean fclean re 