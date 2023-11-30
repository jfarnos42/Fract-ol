NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Imlx
xFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
RM = rm -rf

SRC = fractol.c mandelbrot.c input_manager.c

OBJ_DIR = obj
OBJ	= $(addprefix ${OBJ_DIR}/, ${SRC:%.c=%.o})

all: $(NAME)

${NAME}: ${OBJ}
	@${MAKE} -C ./Libft
	@${MAKE} -C ./ft_printf
	@${CC} ${CFLAGS} ${OBJ} ./Libft/libft.a ./ft_printf/libftprintf.a ${xFLAGS} -o ${NAME}

${OBJ_DIR}/%.o:./%.c
	@mkdir -p ${OBJ_DIR}
	gcc ${FLAGS} -c $< -o $@

clean:
	@${MAKE} -C ./Libft fclean
	@${MAKE} -C ./ft_printf fclean
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re