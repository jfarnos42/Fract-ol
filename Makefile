NAME = fractol
CC = gcc -O3
CFLAGS = -Wall -Wextra -Werror -Imlx
xFLAGS = -lmlx -framework OpenGL -framework AppKit
DEBUG = -fsanitize=address -g3
RM = rm -rf

SRC = main.c engine.c input_manager.c mandelbrot.c julia.c

OBJ_DIR = obj
OBJ	= $(addprefix ${OBJ_DIR}/, ${SRC:%.c=%.o})

all: $(NAME)

${NAME}: ${OBJ}
	@${MAKE} -C ./includes/Libft
	@${MAKE} -C ./includes/ft_printf
	@${CC} ${CFLAGS} ${OBJ} ./includes/Libft/libft.a ./includes/ft_printf/libftprintf.a ${xFLAGS} -o ${NAME}

${OBJ_DIR}/%.o:./%.c
	@mkdir -p ${OBJ_DIR}
	gcc ${CFLAGS} -c $< -o $@

clean:
	@${MAKE} -C ./includes/Libft fclean
	@${MAKE} -C ./includes/ft_printf fclean
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

debug: CFLAGS += $(DEBUG)
debug: re

re: fclean all

.PHONY: all clean fclean debug re