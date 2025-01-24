# main() function in
MAIN_FILE_NAME = minirt
MAIN = $(addsuffix .c, $(MAIN_FILE_NAME))

# Parser for argument file
PARSER_DIR = parser/
PARSER_FILE_NAME = parser
PARSER = $(addprefix $(PARSER_DIR), $(addsuffix .c, $(PARSER_FILE_NAME)))

# Camera
CAMERA_DIR = graphics/camera/
CAMERA_FILE_NAME =	ksx_camera \
					ksx_camera_01
CAMERA = $(addprefix $(CAMERA_DIR), $(addsuffix .c, $(CAMERA_FILE_NAME)))

CYLINDER_DIR = graphics/cylinder/
CYLINDER_FILE_NAME = ksx_cylinder
CYLINDER = $(addprefix $(CYLINDER_DIR), $(addsuffix .c, $(CYLINDER_FILE_NAME)))

LINE_DIR = graphics/line/
LINE_FILE_NAME = ksx_line
LINE = $(addprefix $(LINE_DIR), $(addsuffix .c, $(LINE_FILE_NAME)))

# Sources
SRC_DIR = ./src/
SRC = 	$(CAMERA) \
		$(CYLINDER) \
		$(LINE) \
		$(PARSER) \
		$(MAIN)

SRCS =	$(addprefix $(SRC_DIR), $(SRC))

OBJ_DIR = ./build/
OBJS = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIBFT_DIR = ./lib/libft/
LIBFT_INCLUDE = ./lib/libft/
LIBFT = $(LIBFT_DIR)libft.a

MINILIBX_DIR = ./lib/minilibx/
MINILIBX_INCLUDE = ./lib/minilibx/
MINILIBX = $(MINILIBX_DIR)libx.a

LIB =	$(LIBFT) \
		$(MINILIBX)

# Includs
INCLUDE_DIR = ./include/
# INCLUDE =	$(addsuffix .h, $(CAMERA_FILE_NAME)) \
# 			$(addsuffix .h, $(PARSER_FILE_NAME)) \
# 			$(addsuffix .h, $(CYLINDER_FILE_NAME)) \
# 			$(addsuffix .h, $(LINE_FILE_NAME)) \
# 			$(addsuffix .h, $(MAIN_FILE_NAME))

INCLUDE_DIRS =	$(addprefix -I, $(INCLUDE_DIR)) \
				$(addprefix -I, $(LIBFT_INCLUDE)) \
				$(addprefix -I, $(MINILIBX_INCLUDE))

NAME = minirt
CC = cc
CCFLAGS = -g -Wall -Wextra -Werror

$(NAME): $(OBJ_DIR) $(OBJS) $(LIB)
	@echo NAME:
	@echo $(NAME)
	$(CC) $(CCFLAGS) $(OBJS) $(INCLUDE_DIRS) -o $(NAME)

$(OBJ_DIR):
	@echo OBJ_DIR:
	@echo $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)$(PARSER_DIR)
	mkdir -p $(OBJ_DIR)$(CAMERA_DIR)
	mkdir -p $(OBJ_DIR)$(CYLINDER_DIR)
	mkdir -p $(OBJ_DIR)$(LINE_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCLUDE_DIRS)
# %.o: %.c
	@echo compile .c to .o
	@echo $<
	$(CC) $(CCFLAGS) $(INCLUDE_DIRS) -c $< -o $@

$(LIB):
	@echo LIB:
	@echo $(LIB)
	$(MAKE) -C $(MINILIBX_DIR)
	$(MAKE) -C $(LIBFT_DIR)

all: $(NAME)
	@echo all:

clean:
#	$(MAKE) clean -C $(MINILIBX_DIR)
#	$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
#	$(MAKE) fclean -C $(MINILIBX_DIR)
#	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)

re: fclean all

test:
#	@echo Automatic Variables
#	@echo $<
	@echo SRC:
	@echo $(SRC)
	@echo SRCS:
	@echo $(SRCS)
	@echo INCLUDE_DIRS:
	@echo $(INCLUDE_DIRS)
	@echo OBJ:
	@echo $(OBJ)
	@echo OBJS:
	@echo $(OBJS)

.PHONY: all clean fclean re

# INCLUDE_PATH = ./include/

# MANDATORY_PATH = ./src/
# MANDATORY = \
# minirt \
# graphics/ksx_init \
# graphics/ksx_prep

# MANDATORY_SRC = $(addprefix $(MANDATORY_PATH), $(addsuffix .c, $(MANDATORY)))
# MANDATORY_OBJ = $(MANDATORY_SRC:.c=.o)

# NO_BONUS = \
# graphics/fdf_utils \
# graphics/init \
# graphics/ksx_prep

# NO_BONUS_SRC = $(addprefix $(MANDATORY_PATH), $(addsuffix .c, $(NO_BONUS)))
# NO_BONUS_OBJ = $(NO_BONUS_SRC:.c=.o)

# BONUS_PATH = ./source_bonus/
# BONUS = \
# fdf_hook01 \
# fdf_hook04 \
# fdf_hook_mouse01 \
# fdf_hook03 \
# fdf_hook02 \
# fdf_utils \
# init \

# BONUS_SRC = $(addprefix $(BONUS_PATH), $(addsuffix _bonus.c, $(BONUS)))
# BONUS_OBJ = $(BONUS_SRC:.c=.o)

# LIBFT = ft
# LIBFT_PATH = ./libft/
# LIBFT_NAME = libft.a

# LIBMLX = mlx
# LIBMLX_PATH = ./minilibx-linux/
# LIBMLX_NAME = libmlx.a

# LIBS_PATH = ./libs/
# LIBS = -l${LIBFT} -l${LIBMLX} -lm -lXext -lX11

# $(NAME): ${LIBMLX_NAME} ${LIBFT_NAME} ${MANDATORY_OBJ}
# 	${CC} ${CCFLAGS} -I${INCLUDE_PATH} -L${LIBS_PATH} ${MANDATORY_OBJ} ${LIBS} -o ${NAME}

# all: $(NAME)

# bonus: ${LIBMLX_NAME} ${LIBFT_NAME}  ${MANDATORY_OBJ} ${BONUS_OBJ}
# 	${CC} ${CCFLAGS} -I${INCLUDE_PATH} -L${LIBS_PATH} ${MANDATORY_OBJ} ${BONUS_OBJ} ${LIBS} -o ${NAME}

# %.o: %.c
# 	$(CC) $(CCFLAGS) -I${INCLUDE_PATH} -c $< -o $@

# ${LIBMLX_NAME}:
# 	$(MAKE) -C ${LIBMLX_PATH}
# 	mkdir -p ${LIBS_PATH}
# 	cp -f $(LIBMLX_PATH)${LIBMLX_NAME} ${LIBS_PATH}${LIBMLX_NAME}

# ${LIBFT_NAME}:
# 	$(MAKE) -C ${LIBFT_PATH}
# 	mkdir -p ${LIBS_PATH}
# 	cp -f $(LIBFT_PATH)${LIBFT_NAME} ${LIBS_PATH}${LIBFT_NAME}

# clean:
# 	$(MAKE) clean -C ${LIBMLX_PATH}
# 	$(MAKE) clean -C ${LIBFT_PATH}
# 	rm -f $(MANDATORY_OBJ)
# 	rm -f $(BONUS_OBJ)

# fclean: clean
# 	$(MAKE) fclean -C ${LIBFT_PATH}
# 	rm -f $(NAME)
# 	rm -f $(LIBS_PATH)${LIBFT_NAME}
# 	rm -f $(LIBS_PATH)${LIBMLX_NAME}

re: fclean all