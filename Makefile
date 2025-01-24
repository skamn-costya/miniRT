# main() function in
MAIN = minirt.c

# Parser for argument file
PARSER_DIR = parser/
PARSER_FILE_NAME = parser01.c
PARSER = $(addprefix $(PARSER_DIR), $(PARSER_FILE_NAME))

# Camera
CAMERA_DIR = graphics/camera/
CAMERA_FILE_NAME =	ksx_camera_01.c \
					ksx_camera_02.c
CAMERA = $(addprefix $(CAMERA_DIR), $(CAMERA_FILE_NAME))

CYLINDER_DIR = graphics/cylinder/
CYLINDER_FILE_NAME = ksx_cylinder01.c
CYLINDER = $(addprefix $(CYLINDER_DIR), $(CYLINDER_FILE_NAME))

LINE_DIR = graphics/line/
LINE_FILE_NAME = ksx_line01.c
LINE = $(addprefix $(LINE_DIR), $(LINE_FILE_NAME))

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
LIBFT_INCLUDE = ./lib/libft/include
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_DIR)$(LIBFT_NAME)

MINILIBX_DIR = ./lib/minilibx/
MINILIBX_INCLUDE = ./lib/minilibx/
MINILIBX_NAME = libmlx.a
MINILIBX = $(MINILIBX_DIR)$(MINILIBX_NAME)

LIB_DIRS =	$(addprefix -L, $(LIBFT_DIR)) \
			$(addprefix -L, $(MINILIBX_DIR))
LIBS =	$(LIBFT_NAME:lib%.a=-l%) \
		$(MINILIBX_NAME:lib%.a=-l%) \


# Includes
DIR_INCLUDE = ./include/
INCLUDE_DIRS =	$(addprefix -I, $(DIR_INCLUDE)) \
				$(addprefix -I, $(LIBFT_INCLUDE)) \
				$(addprefix -I, $(MINILIBX_INCLUDE))

NAME = minirt
CC = cc
CCFLAGS = -g -Wall -Wextra -Werror

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBS)
	$(CC) $(CCFLAGS) $(OBJS) $(INCLUDE_DIRS) $(LIB_DIRS) $(LIBS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)$(PARSER_DIR)
	mkdir -p $(OBJ_DIR)$(CAMERA_DIR)
	mkdir -p $(OBJ_DIR)$(CYLINDER_DIR)
	mkdir -p $(OBJ_DIR)$(LINE_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CCFLAGS) $(INCLUDE_DIRS) -c $< -o $@

$(LIBS):
	$(MAKE) -C $(MINILIBX_DIR)
	$(MAKE) -C $(LIBFT_DIR)

all: $(NAME)

clean:
	$(MAKE) clean -C $(MINILIBX_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
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
