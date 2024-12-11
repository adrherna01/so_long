CC = gcc

CFLAGS = -Wall -Wextra -Werror -I./MLX42/include -Iincludes/

NAME = so_long

# Directories
SRC_DIR = src/
OBJ_DIR = obj/
LIBFT_DIR = libft
MLX42_DIR = MLX42

# Gather all source files recursively
SRC = $(wildcard $(SRC_DIR)/**/*.c) $(wildcard $(SRC_DIR)/*.c)

# Map source files to object files
OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a
LIBMLX42 = $(MLX42_DIR)/build/libmlx42.a
MLX_FLAGS = -L$(MLX42_DIR)/build -lmlx42 -lglfw -framework OpenGL -framework AppKit

all: $(NAME)

# Compile each source file into its corresponding object file
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Link all object files and libraries to create the executable
$(NAME): $(OBJ) $(LIBFT) $(LIBMLX42)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $@

# Build libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Build MLX42 library
$(LIBMLX42):
	cd $(MLX42_DIR) && cmake -B build && cmake --build build -j4

# Clean object files and library builds
clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean
	cd $(MLX42_DIR) && rm -rf build

# Clean everything including the executable
fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re