SOURCES	=	main.c utils.c sets.c hooks.c input_check.c complex_functions.c
OBJECTS	=	$(addprefix $(BUILD)/, $(SOURCES:.c=.o))
NAME	=	fractol
CC		=	gcc
BUILD	=	build

FLAGS	=	-Wall -Werror -Wextra
INC_DIR	=	-I include -I lib/libft -I lib/MLX42/include/MLX42
LIBS	=	$(MLX) $(LIBFT) 
LDFLAGS	=	-lglfw3 -OpenGL -framework Cocoa -framework IOKit
MLX		=	lib/MLX42/libmlx42.a
LIBFT	=	lib/libft/libft.a
MLX_DIR	=	lib/MLX42
LIBFT_D	=	lib/libft

all:	$(NAME)

$(NAME): $(OBJECTS) $(LIBS)
	$(CC) $(LDFLAGS) $(OBJECTS) $(LIBS) -o $(NAME)

$(LIBS):
	@$(MAKE) -C $(MLX_DIR) -s
	@$(MAKE) -C $(LIBFT_D) -s

$(BUILD)/%.o: %.c | $(BUILD)
	@$(CC) $(FLAGS) $(INC_DIR) -c $< -o $@

$(BUILD):
	@mkdir -p build

clean:
	@rm -rf $(OBJECTS) $(BUILD)
	@$(MAKE) -C $(MLX_DIR) clean -s
	@$(MAKE) -C $(LIBFT_D) clean -s

fclean:
	@rm -rf $(NAME) $(OBJECTS) $(BUILD)
	@$(MAKE) -C $(MLX_DIR) fclean -s 
	@$(MAKE) -C $(LIBFT_D) fclean -s

re:	fclean all

.PHONY: all clean fclean re