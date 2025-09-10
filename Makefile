NAME = pushSwap
UNAME = $(shell uname -s)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Wpedantic -pedantic-errors -g
LDFLAGS = -L ./libft -lft

RM = rm -f

LIBFT = ./libft/libft.a

SRC_DIR = src

SRC = main.c shuffle.c arr_utils.c

OBJ_DIR = objects

SRC_OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

DEP_FILES = $(SRC_OBJ:.o=.d)  # Dependency files

BONUS_DEP_FILES = $(BONUS_OBJ:.o=.d)

PURPLE = \033[0;34m
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)
	@printf "$(GREEN)Compilation OK!$(RESET)\n"

$(NAME): $(SRC_OBJ) $(LIBFT)
	@printf "$(PURPLE)Linking $(NAME)...$(RESET)\n"
	$(CC) $(CFLAGS) $(SRC_OBJ) $(LDFLAGS) -o $(NAME) -I ./includes

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@printf "$(PURPLE)Compiling $< (main)...$(RESET)\n"
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@ -I ./includes

$(OBJ_DIR)/%.o: $(SRC_DIR)/*/%.c | $(OBJ_DIR)
	@printf "$(PURPLE)Compiling $< (main)...$(RESET)\n"
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@ -I ./includes

-include $(DEP_FILES)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@$(MAKE) -C ./libft

clean:
	@printf "$(RED)Cleaning object and dependency files...$(RESET)\n"
	$(RM) $(OBJ_DIR)/*.o $(OBJ_DIR)/*.d
	@$(MAKE) -C ./libft clean

fclean: clean
	@printf "$(RED)Removing executables and objects directories...$(RESET)\n"
	$(RM) $(NAME)
	$(RM) -r $(OBJ_DIR)
	@$(MAKE) -C ./libft fclean

re: fclean all

valgrind: all
	@valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME)

run: all
	@./$(NAME)

norm:
	@norminette ./src ./includes ./libft

.PHONY: all clean fclean re valgrind run norm
