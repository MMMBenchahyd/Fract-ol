NAME = fractol
NAME_BONUS = fractol_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = Mandatory
SRC_DIR_BONUS = Bonus

OBJ_DIR = objects
OBJ_DIR_BONUS = objects_bonus

SRCS = $(SRC_DIR)/color_func.c $(SRC_DIR)/fractol_func.c $(SRC_DIR)/atodouble.c $(SRC_DIR)/hooks_func.c $(SRC_DIR)/func_helper.c $(SRC_DIR)/main.c \
	$(SRC_DIR)/zoom.c $(SRC_DIR)/func_helper1.c 
SRCS_BONUS = $(SRC_DIR_BONUS)/color_func_bonus.c $(SRC_DIR_BONUS)/fractol_func_bonus.c $(SRC_DIR_BONUS)/atodouble_bonus.c $(SRC_DIR_BONUS)/hooks_func_bonus.c $(SRC_DIR_BONUS)/func_helper_bonus.c $(SRC_DIR_BONUS)/main_bonus.c \
	$(SRC_DIR_BONUS)/zoom_translate_bonus.c $(SRC_DIR_BONUS)/func_helper1_bonus.c

HEADERS = $(SRC_DIR)/fractol.h
HEADERS_BONUS = $(SRC_DIR_BONUS)/fractol_bonus.h $(SRC_DIR_BONUS)/bottons_bonus.h

OBJ = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_BONUS = $(SRCS_BONUS:$(SRC_DIR_BONUS)/%.c=$(OBJ_DIR_BONUS)/%.o)

all: $(OBJ_DIR) $(NAME)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) -o $@ $(OBJ_BONUS)  -lmlx \
		 -framework OpenGL -framework AppKit 

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)  -lmlx \
		-framework OpenGL -framework AppKit


$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c	$(HEADERS)	|	$(OBJ_DIR)
	$(CC)	$(CFLAGS)	-o	$@	-c	$<

$(OBJ_DIR_BONUS)/%.o:	$(SRC_DIR_BONUS)/%.c	$(HEADERS_BONUS)	|	$(OBJ_DIR_BONUS)
	$(CC)	$(CFLAGS)	-o	$@	-c	$<

$(OBJ_DIR):
	mkdir $@

$(OBJ_DIR_BONUS):
	mkdir $@

clean:
	rm -rf $(OBJ_DIR) $(OBJ_DIR_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

bonus: $(OBJ_DIR_BONUS) $(NAME_BONUS)

re: fclean all
