SOURCES	=	main.c utils.c mandelbrot.c
OBJECTS	=	$(addprefix $(BUILD)/, $(SOURCES:.c=.o))
NAME	=	fractol
CC		=	gcc
FLAGS	=	-Wall -Werror -Wextra
BUILD	=	build

LIBS	=	$(MLX)/libmlx42.a -I include -lglfw3 -framework Cocoa -OpenGL -framework IOKit $(LIBFT)/libft.a
MLX		=	lib/MLX42
LIBFT	=	lib/libft


all:	$(NAME)

$(NAME): $(OBJECTS) $(LIBS)
	$(CC) $(FLAGS) $(OBJECTS) $(LIBS) -o $(NAME)

$(LIBS):
	@$(MAKE) -C $(MLX) -s
	@$(MAKE) -C $(LIBFT) -s

$(BUILD)/%.o: %.c | $(BUILD)
	@$(CC) -c $< -o $@

$(BUILD):
	@mkdir -p build

clean:
	@rm -rf $(OBJECTS) $(BUILD)
	@$(MAKE) -C $(MLX) clean -s
	@$(MAKE) -C $(LIBFT) clean -s

fclean:
	@rm -rf $(NAME) $(OBJECTS) $(BUILD)
	@$(MAKE) -C $(MLX) fclean -s 
	@$(MAKE) -C $(LIBFT) fclean -s

re:	fclean all