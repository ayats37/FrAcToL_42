SRCS = window.c main.c mandelbrot.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

NAME = fractol

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re