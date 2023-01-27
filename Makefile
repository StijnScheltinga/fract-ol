SOURCES	=	main.c utils.c mandelbrot.c
OBJECTS	=	$(SOURCES:.c=.o)
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
	$(MAKE) -C $(MLX)
	$(MAKE) -C $(LIBFT)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -rf $(OBJECTS)
	$(MAKE) -C $(MLX) clean
	$(MAKE) -C $(LIBFT) clean

fclean:
	rm -rf $(NAME) $(OBJECTS)
	$(MAKE) -C $(MLX) fclean
	$(MAKE) -C $(LIBFT) fclean

re:	fclean all