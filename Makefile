# main() function in
MAIN = minirt.c

# Argument file parser
PARSER_DIR = parser/
PARSER_FN =	parser01.c \
			parser02.c \
			parser03.c \
			parser04.c \
			parser05.c
PARSER = $(addprefix $(PARSER_DIR), $(PARSER_FN))

# KSX utilites
UTILS_DIR = graphics/utils/
UTILS_FN =	ksx_utils04.c \
			ksx_utils05.c \
			ksx_utils08.c \
			ksx_utils09.c
UTILS = $(addprefix $(UTILS_DIR), $(UTILS_FN))

# KSX t_vector math
VECTOR_MATH_DIR = graphics/utils/vector_math/
VECTOR_MATH_FN =	ksx_vec3_math01.c \
					ksx_vec3_math02.c \
					ksx_vec3_math03.c \
					ksx_vec4_math01.c \
					ksx_vec4_math02.c \
					ksx_vec4_math03.c
VECTOR_MATH = $(addprefix $(VECTOR_MATH_DIR), $(VECTOR_MATH_FN))

# KSX t_vector math
MATRIX_MATH_DIR = graphics/utils/matrix_math/
MATRIX_MATH_FN =	ksx_m4_math01.c \
					ksx_m4_math02.c \
					ksx_m4_math03.c \
					ksx_m3_math01.c
MATRIX_MATH = $(addprefix $(MATRIX_MATH_DIR), $(MATRIX_MATH_FN))

3D_DIR = graphics/3D/
3D_FN = ksx_draw_obj.c \
		ksx_draw_axis.c \
		ksx_draw_box.c \
		ksx_draw_tris.c \
		ksx_draw_tri.c \
		ksx_draw_get_pixel.c \
		ksx_draw_vertex.c
3D = $(addprefix $(3D_DIR), $(3D_FN))

BASIS_DIR = graphics/basis/
BASIS_FN =	ksx_basis.c \
			ksx_basis_move.c \
			ksx_basis_rotation.c
BASIS = $(addprefix $(BASIS_DIR), $(BASIS_FN))

# Rotatin pints, vectors, triangles, matrixes (view, proection)
OBJECT_DIR = graphics/object/
OBJECT_FN =	ksx_object01.c \
			ksx_object02.c \
			ksx_object03.c \
			ksx_qrotation.c \
			ksx_translate.c \
			ksx_transform.c
OBJECT = $(addprefix $(OBJECT_DIR), $(OBJECT_FN))

# Camera object
CAMERA_DIR = graphics/camera/
CAMERA_FN =	ksx_camera01.c \
			ksx_camera02.c
CAMERA = $(addprefix $(CAMERA_DIR), $(CAMERA_FN))

# Sphere object
SPHERE_DIR = graphics/sphere/
SPHERE_FN = ksx_sphere01.c \
			ksx_sphere02.c
SPHERE = $(addprefix $(SPHERE_DIR), $(SPHERE_FN))

# Cylinder object
CYLINDER_DIR = graphics/cylinder/
CYLINDER_FN =	ksx_cylinder01.c \
				ksx_cylinder02.c
CYLINDER = $(addprefix $(CYLINDER_DIR), $(CYLINDER_FN))

# Draw shapes functions
SHAPES_DIR = graphics/shapes/
SHAPES_FN = ksx_pixel.c \
			ksx_line.c \
			ksx_circle.c
SHAPES = $(addprefix $(SHAPES_DIR), $(SHAPES_FN))

# Graphics utilites
GRAPHICS_DIR = graphics/
GRAPHICS_FN =	ksx_draw.c \
				ksx_init.c \
				ksx_prep.c \
				ksx_world.c
GRAPHICS =	$(addprefix $(GRAPHICS_DIR), $(GRAPHICS_FN))

# All sources
SRC_DIR = ./src/
SRC = 	$(UTILS) \
		$(VECTOR_MATH) \
		$(MATRIX_MATH) \
		$(3D) \
		$(BASIS) \
		$(OBJECT) \
		$(CAMERA) \
		$(SPHERE) \
		$(CYLINDER) \
		$(SHAPES) \
		$(GRAPHICS) \
		$(PARSER) \
		$(MAIN) \
		utils01.c \
		key_kp01.c \
		key_kp02.c \
		key_arrows.c \
		key_adsw.c
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

# All libraries
LIB_DIRS =	$(LIBFT_DIR) \
			$(MLX42_DIR)
LIBS =	$(LIBFT_NAME) \
		$(MLX42_NAME)

# Include pathes
DIR_INCLUDE = ./include/
INCLUDE_DIRS =	$(DIR_INCLUDE) \
				$(LIBFT_INCLUDE) \
				$(MLX42_INCLUDE)

NAME = minirt
CC = cc
CCFLAGS = -g -Wall -Wextra -Werror

$(NAME): $(OBJ_DIR) $(OBJS) make_lib
	$(CC) $(CCFLAGS) $(OBJS) $(INCLUDE_DIRS:%=-I%) $(LIB_DIRS:%=-L%) $(LIBS:lib%.a=-l%) -lm -ldl -lglfw -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)$(PARSER_DIR)
	mkdir -p $(OBJ_DIR)$(UTILS_DIR)
	mkdir -p $(OBJ_DIR)$(VECTOR_MATH_DIR)
	mkdir -p $(OBJ_DIR)$(MATRIX_MATH_DIR)
	mkdir -p $(OBJ_DIR)$(BASIS_DIR)
	mkdir -p $(OBJ_DIR)$(3D_DIR)
	mkdir -p $(OBJ_DIR)$(OBJECT_DIR)
	mkdir -p $(OBJ_DIR)$(CAMERA_DIR)
	mkdir -p $(OBJ_DIR)$(SPHERE_DIR)
	mkdir -p $(OBJ_DIR)$(CYLINDER_DIR)
	mkdir -p $(OBJ_DIR)$(SHAPES_DIR)

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
