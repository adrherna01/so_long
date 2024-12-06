

CC = gcc


CFLAGS = -Wall -Wextra -Werror -I./MLX42/include -Iinc/


RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
MAGENTA = \033[1;35m
CYAN = \033[1;36m
RESET = \033[0m


NAME = so_long


SRC_DIR = .
OBJ_DIR = obj/
LIBFT_DIR = libft
MLX42_DIR = MLX42
INC_DIR = inc/


SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT = $(LIBFT_DIR)/libft.a
LIBMLX42 = $(MLX42_DIR)/build/libmlx42.a
MLX_FLAGS = -L$(MLX42_DIR)/build -lmlx42 -lglfw -framework OpenGL -framework AppKit


all: | $(OBJ_DIR) $(NAME)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "$(CYAN)Starting compilation process for $<...$(RESET)"
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BLUE)Compiled $< to $@.$(RESET)"
	@echo "$(CYAN)Compilation process for $< finished.$(RESET)"


$(NAME): $(OBJ) | $(LIBFT) $(LIBMLX42)
	@echo "$(CYAN)Starting linking process...$(RESET)"
	@echo "$(YELLOW)Linking object files...$(RESET)"
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $@
	@echo "$(GREEN)Linking done. Executable created: $(NAME)$(RESET)"
	@echo "$(CYAN)Linking process finished.$(RESET)"


$(LIBFT):
	make -C $(LIBFT_DIR)

$(LIBMLX42):
	cd $(MLX42_DIR) && cmake -B build && cmake --build build -j4


$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)


clean:
	@echo "$(CYAN)Starting cleaning process...$(RESET)"
	@echo "$(MAGENTA)Cleaning object files...$(RESET)"
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean
	cd $(MLX42_DIR) && rm -rf build
	@echo "$(RED)Cleaning done.$(RESET)"
	@echo "$(CYAN)Cleaning process finished.$(RESET)"


fclean: clean
	@echo "$(CYAN)Starting full cleaning process...$(RESET)"
	@echo "$(MAGENTA)Full cleaning...$(RESET)"
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	@echo "$(RED)Full cleaning done. Removed executable: $(NAME)$(RESET)"
	@echo "$(CYAN)Full cleaning process finished.$(RESET)"


re: fclean all

.PHONY: all clean fclean re
