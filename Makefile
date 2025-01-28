# main() function in
MAIN = minirt.c

# Argument file parser
PARSER_DIR = parser/
PARSER_FN =	parser01.c \
			parser02.c \
			parser03.c \
			parser04.c
PARSER = $(addprefix $(PARSER_DIR), $(PARSER_FN))

# Camera object
CAMERA_DIR = graphics/camera/
CAMERA_FN =	ksx_camera_01.c \
			ksx_camera_02.c
CAMERA = $(addprefix $(CAMERA_DIR), $(CAMERA_FN))

# Cylinder object
CYLINDER_DIR = graphics/cylinder/
CYLINDER_FN = ksx_cylinder01.c
CYLINDER = $(addprefix $(CYLINDER_DIR), $(CYLINDER_FN))

# Draw line function
LINE_DIR = graphics/line/
LINE_FN = ksx_line01.c
LINE = $(addprefix $(LINE_DIR), $(LINE_FN))

# Graphics utilites
GRAPHICS_DIR = graphics/
GRAPHICS_FN =	ksx_draw.c
GRAPHICS =	$(addprefix $(GRAPHICS_DIR), $(GRAPHICS_FN))

# All sources
SRC_DIR = ./src/
SRC = 	$(CAMERA) \
		$(CYLINDER) \
		$(LINE) \
		$(GRAPHICS) \
		$(PARSER) \
		$(MAIN) \
		utils01.c
SRCS =	$(addprefix $(SRC_DIR), $(SRC))

# All .o files
OBJ_DIR = ./build/
OBJS = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

# My libft library
LIBFT_DIR = ./lib/libft/
LIBFT_INCLUDE = ./lib/libft
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_DIR)$(LIBFT_NAME)

# # The MinilibX
# MINILIBX_DIR = ./lib/minilibx/
# MINILIBX_INCLUDE = ./lib/minilibx/
# MINILIBX_NAME = libmlx.a
# MINILIBX = $(MINILIBX_DIR)$(MINILIBX_NAME)

# The MLX42
MLX42_BUILD_DIR = ./lib/MLX42/
MLX42_DIR = ./lib/MLX42/build/
MLX42_INCLUDE = ./lib/MLX42/include/MLX42/
MLX42_NAME = libmlx42.a
MLX42 = $(MLX42_DIR)$(MLX42_NAME)

# The math library
LIBM_NAME = libm.a

# All libraries
LIB_DIRS =	$(LIBFT_DIR) \
			$(MLX42_DIR)
LIBS =	$(LIBFT_NAME) \
		$(MLX42_NAME) \
		$(LIBM_NAME)

# Include pathes
DIR_INCLUDE = ./include/
INCLUDE_DIRS =	$(DIR_INCLUDE) \
				$(LIBFT_INCLUDE) \
				$(MLX42_INCLUDE)

NAME = minirt
CC = cc
CCFLAGS = -g -Wall -Wextra -Werror

$(NAME): $(OBJ_DIR) $(OBJS) make_lib
	$(CC) $(CCFLAGS) $(OBJS) $(INCLUDE_DIRS:%=-I%) $(LIB_DIRS:%=-L%) $(LIBS:lib%.a=-l%) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)$(PARSER_DIR)
	mkdir -p $(OBJ_DIR)$(CAMERA_DIR)
	mkdir -p $(OBJ_DIR)$(CYLINDER_DIR)
	mkdir -p $(OBJ_DIR)$(LINE_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CCFLAGS) $(INCLUDE_DIRS:%=-I%) -c $< -o $@

make_lib:
	$(MAKE) -C $(LIBFT_DIR)
	cd $(MLX42_BUILD_DIR) && cmake -B build
	cd $(MLX42_BUILD_DIR) && cmake --build build

all: $(NAME)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	cd $(MLX42_BUILD_DIR) && cmake --build build --target clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)

re: fclean all

# test:
# 	@echo Automatic Variables
# 	@echo $<
# 	@echo SRC:
# 	@echo $(SRC)
# 	@echo SRCS:
# 	@echo $(SRCS)
# 	@echo INCLUDE_DIRS:
# 	@echo $(INCLUDE_DIRS)
# 	@echo OBJ:
# 	@echo $(OBJ)
# 	@echo OBJS:
# 	@echo $(OBJS)

.PHONY: all clean fclean re
