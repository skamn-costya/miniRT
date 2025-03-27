# main() function in
MAIN = minirt.c

# Argument file parser
PARSER_DIR = parser/
PARSER_FN =	parser01.c \
			parser02.c \
			parser03.c \
			parser04.c \
			parser05.c \
			parser06.c
PARSER = $(addprefix $(PARSER_DIR), $(PARSER_FN))

# KSX utilites
UTILS_DIR = graphics/utils/
UTILS_FN =	ksx_utils01.c \
			ksx_utils04.c \
			ksx_utils08.c
UTILS = $(addprefix $(UTILS_DIR), $(UTILS_FN))

# work with pointer to pointers structure
PP_STRUCT_DIR = graphics/utils/pp_struct/
PP_STRUCT_FN =	pp_struct01.c \
				pp_struct02.c
PP_STRUCT = $(addprefix $(PP_STRUCT_DIR), $(PP_STRUCT_FN))

# KSX t_vector math
VECTOR_MATH_DIR = graphics/utils/vector_math/
VECTOR_MATH_FN =	ksx_vec3_math01.c \
					ksx_vec3_math02.c \
					ksx_vec3_math03.c \
					ksx_vec3_math04.c \
					ksx_vec4_math01.c \
					ksx_vec4_math02.c \
					ksx_vec4_math03.c
VECTOR_MATH = $(addprefix $(VECTOR_MATH_DIR), $(VECTOR_MATH_FN))

# KSX t_vector math
MATRIX_MATH_DIR = graphics/utils/matrix_math/
MATRIX_MATH_FN =	ksx_m4_math01.c \
					ksx_m4_math02.c \
					ksx_m4_math03.c \
					ksx_m3_math01.c \
					ksx_m3_math02.c
MATRIX_MATH = $(addprefix $(MATRIX_MATH_DIR), $(MATRIX_MATH_FN))

3D_DIR = graphics/3D/
3D_FN = ksx_draw_obj.c \
		ksx_draw_axis.c \
		ksx_draw_box.c \
		ksx_draw_tris.c \
		ksx_draw_tri.c \
		ksx_draw_get_pixel.c \
		ksx_draw_vertex.c \
		ksx_draw_norm.c
3D = $(addprefix $(3D_DIR), $(3D_FN))

BASIS_DIR = graphics/basis/
BASIS_FN =	ksx_basis01.c \
			ksx_basis02.c \
			ksx_basis_move.c \
			ksx_basis_rotation.c
BASIS = $(addprefix $(BASIS_DIR), $(BASIS_FN))

# Rotatin pints, vectors, triangles, matrixes (view, proection)
OBJECT_DIR = graphics/object/
OBJECT_FN =	ksx_object01.c \
			ksx_object02.c \
			ksx_object03.c \
			ksx_qrotation.c \
			ksx_transform.c \
			ksx_norms.c
OBJECT = $(addprefix $(OBJECT_DIR), $(OBJECT_FN))

OBJ_FILE_DIR = graphics/obj_file/
OBJ_FILE_FN = ksx_obj_file.c
OBJ_FILE = $(addprefix $(OBJ_FILE_DIR), $(OBJ_FILE_FN))

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

# Cone object
CONE_DIR = graphics/cone/
CONE_FN =	ksx_cone01.c
CONE = $(addprefix $(CONE_DIR), $(CONE_FN))

# Draw shapes functions
SHAPES_DIR = graphics/shapes/
SHAPES_FN = ksx_pixel.c \
			ksx_line01.c \
			ksx_line02.c \
			ksx_circle.c
SHAPES = $(addprefix $(SHAPES_DIR), $(SHAPES_FN))

# Graphics utilites
GRAPHICS_DIR = graphics/
GRAPHICS_FN =	ksx_change.c \
				ksx_draw.c \
				ksx_init.c \
				ksx_image.c \
				ksx_gc.c
GRAPHICS =	$(addprefix $(GRAPHICS_DIR), $(GRAPHICS_FN))

# Keys
KYES_DIR = graphics/keys/
KYES_FN =	key_kp01.c \
			key_kp02.c \
			key_arrows.c \
			key_adsw.c \
			key_ze.c \
			key_scroll.c \
			key_f.c \
			key_f5_f8.c \
			key_f9_f12.c \
			key_90-=.c
KYES =	$(addprefix $(KYES_DIR), $(KYES_FN))

# Boxes
BOXES_DIR = graphics/boxes/
BOXES_FN =	ksx_boxes.c
BOXES =	$(addprefix $(BOXES_DIR), $(BOXES_FN))

# Triangle
TRIANGLE_DIR = graphics/triangle/
TRIANGLE_FN =	ksx_triangle.c
TRIANGLE =	$(addprefix $(TRIANGLE_DIR), $(TRIANGLE_FN))

# World
WORLD_DIR = graphics/world/
WORLD_FN =	ksx_world01.c \
			ksx_world02.c \
			ksx_world03.c
WORLD =	$(addprefix $(WORLD_DIR), $(WORLD_FN))

# Light
LIGHT_DIR = graphics/light/
LIGHT_FN =	ksx_light.c
LIGHT =	$(addprefix $(LIGHT_DIR), $(LIGHT_FN))

# Plane
PLANE_DIR = graphics/plane/
PLANE_FN =	ksx_plane.c
PLANE =	$(addprefix $(PLANE_DIR), $(PLANE_FN))

RAY_DIR = ray/
RAY_FN =	ray_cast.c \
			ray_tri.c \
			ray_pln.c \
			ray_color.c \
			ray_lgt.c \
			ray_texture01.c \
			ray_texture02.c \
			ray_texture03.c \
			ray_cast_thread.c

RAY =	$(addprefix $(RAY_DIR), $(RAY_FN))

# BVH
BVH_DIR = bvh/
BVH_FN = bvh_build.c \
				 bvh_debug.c \
				 bvh_utils.c
BVH = $(addprefix $(BVH_DIR), $(BVH_FN))

# All sources
SRC_DIR = ./src/
SRC = 	$(UTILS) \
		$(PP_STRUCT) \
		$(VECTOR_MATH) \
		$(MATRIX_MATH) \
		$(3D) \
		$(BASIS) \
		$(BOXES) \
		$(OBJECT) \
		$(OBJ_FILE) \
		$(CAMERA) \
		$(SPHERE) \
		$(CYLINDER) \
		$(CONE) \
		$(SHAPES) \
		$(GRAPHICS) \
		$(KYES) \
		$(TRIANGLE) \
		$(LIGHT) \
		$(PLANE) \
		$(WORLD) \
		$(RAY) \
		$(BVH) \
		$(PARSER) \
		$(MAIN) \
		gc.c
SRCS =	$(addprefix $(SRC_DIR), $(SRC))

# All .o files
OBJ_DIR = ./build/
OBJS = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

# All bonus .o files
OBJ_DIR_BONUS = bonus/
OBJS_BONUS = $(addprefix $(OBJ_DIR), $(addprefix $(OBJ_DIR_BONUS), $(SRC:.c=.o)))

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

DIRS =	$(PARSER_DIR) \
		$(UTILS_DIR) \
		$(PP_STRUCT_DIR) \
		$(VECTOR_MATH_DIR) \
		$(MATRIX_MATH_DIR) \
		$(BASIS_DIR) \
		$(3D_DIR) \
		$(OBJECT_DIR) \
		$(OBJ_FILE_DIR) \
		$(CAMERA_DIR) \
		$(SPHERE_DIR) \
		$(CYLINDER_DIR) \
		$(CONE_DIR) \
		$(SHAPES_DIR) \
		$(KYES_DIR) \
		$(TRIANGLE_DIR) \
		$(BOXES_DIR) \
		$(LIGHT_DIR) \
		$(PLANE_DIR) \
		$(WORLD_DIR) \
		$(RAY_DIR) \
		$(BVH_DIR)

$(NAME): $(OBJ_DIR) $(OBJS) make_lib
	$(CC) $(CCFLAGS) $(OBJS) $(INCLUDE_DIRS:%=-I%) $(LIB_DIRS:%=-L%) $(LIBS:lib%.a=-l%) -lm -ldl -lglfw -o $(NAME)

BONUS: $(OBJ_DIR_BONUS) $(OBJS_BONUS) make_lib
	$(CC) $(CCFLAGS) $(OBJS_BONUS) $(INCLUDE_DIRS:%=-I%) $(LIB_DIRS:%=-L%) $(LIBS:lib%.a=-l%) -lm -ldl -lglfw -D BONUS -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	for DIR in $(DIRS) ; do \
        mkdir -p $(OBJ_DIR)$$DIR ; \
    done

$(OBJ_DIR_BONUS):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)$(OBJ_DIR_BONUS)
	for DIR in $(DIRS) ; do \
        mkdir -p $(OBJ_DIR)$(OBJ_DIR_BONUS)$$DIR ; \
    done

$(OBJ_DIR)$(OBJ_DIR_BONUS)%.o: $(SRC_DIR)%.c
	$(CC) $(CCFLAGS) $(INCLUDE_DIRS:%=-I%) -D BONUS -c $< -o $@

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

valg:
#	valgrind --leak-check=full --suppressions=mlx.supp ./minirt ./files.rt/example.rt
	valgrind --leak-check=full --show-leak-kinds=all --suppressions=mlx.supp ./minirt ./files.rt/example.rt

run:
	./minirt ./files.rt/example.rt

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
