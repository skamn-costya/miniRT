NAME = miniRT
CC = cc
CCFLAGS = -Wall -Wextra -Werror

INCLUDE_PATH = ./include/

MANDATORY_PATH = ./source/
MANDATORY = \
fdf \
file/file_lst_utils \
file/file_lst \
file/lst_arr \
file/fdf_arr \
graphics/fdf_point \
graphics/fdf_rotation_x \
graphics/fdf_rotation_y \
graphics/fdf_zoom \
graphics/fdf_line \
graphics/fdf_min_nax \
graphics/fdf_prep \
graphics/fdf_draw \
graphics/fdf_rotation_z \
graphics/camera \
graphics/fdf_rotation

MANDATORY_SRC = $(addprefix $(MANDATORY_PATH), $(addsuffix .c, $(MANDATORY)))
MANDATORY_OBJ = $(MANDATORY_SRC:.c=.o)

NO_BONUS = \
graphics/fdf_utils \
graphics/init

NO_BONUS_SRC = $(addprefix $(MANDATORY_PATH), $(addsuffix .c, $(NO_BONUS)))
NO_BONUS_OBJ = $(NO_BONUS_SRC:.c=.o)

BONUS_PATH = ./source_bonus/
BONUS = \
fdf_hook01 \
fdf_hook04 \
fdf_hook_mouse01 \
fdf_hook03 \
fdf_hook02 \
fdf_utils \
init \

BONUS_SRC = $(addprefix $(BONUS_PATH), $(addsuffix _bonus.c, $(BONUS)))
BONUS_OBJ = $(BONUS_SRC:.c=.o)

LIBFT = ft
LIBFT_PATH = ./libft/
LIBFT_NAME = libft.a

LIBMLX = mlx
LIBMLX_PATH = ./minilibx-linux/
LIBMLX_NAME = libmlx.a

LIBS_PATH = ./libs/
LIBS = -l${LIBFT} -l${LIBMLX} -lm -lXext -lX11

$(NAME): ${LIBMLX_NAME} ${LIBFT_NAME} ${MANDATORY_OBJ} ${NO_BONUS_OBJ}
	${CC} ${CCFLAGS} -I${INCLUDE_PATH} -L${LIBS_PATH} ${MANDATORY_OBJ} ${NO_BONUS_OBJ} ${LIBS} -o ${NAME}

all: $(NAME)

bonus: ${LIBMLX_NAME} ${LIBFT_NAME}  ${MANDATORY_OBJ} ${BONUS_OBJ}
	${CC} ${CCFLAGS} -I${INCLUDE_PATH} -L${LIBS_PATH} ${MANDATORY_OBJ} ${BONUS_OBJ} ${LIBS} -o ${NAME}

%.o: %.c
	$(CC) $(CCFLAGS) -I${INCLUDE_PATH} -c $< -o $@

${LIBMLX_NAME}:
	$(MAKE) -C ${LIBMLX_PATH}
	mkdir -p ${LIBS_PATH}
	cp -f $(LIBMLX_PATH)${LIBMLX_NAME} ${LIBS_PATH}${LIBMLX_NAME}

${LIBFT_NAME}:
	$(MAKE) -C ${LIBFT_PATH}
	mkdir -p ${LIBS_PATH}
	cp -f $(LIBFT_PATH)${LIBFT_NAME} ${LIBS_PATH}${LIBFT_NAME}

clean:
	$(MAKE) clean -C ${LIBMLX_PATH}
	$(MAKE) clean -C ${LIBFT_PATH}
	rm -f $(MANDATORY_OBJ)
	rm -f $(BONUS_OBJ)

fclean: clean
	$(MAKE) fclean -C ${LIBFT_PATH}
	rm -f $(NAME)
	rm -f $(LIBS_PATH)${LIBFT_NAME}
	rm -f $(LIBS_PATH)${LIBMLX_NAME}

re: fclean all
