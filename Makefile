NAME = fillit

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra

SRC_PATH = ./srcs/
INC_PATH = ./includes/
OBJ_PATH = ./obj/
LBFT_PATH = ./libft/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
DELETE = $(OBJ)

OBJ_NAME = $(SRC_NAME:.c=.o)

INC_NAME = fillit.h

SRC_NAME = main.c action_tets.c tetri_check.c find_block.c fill_map.c \
		   get_solvable.c map_fts.c tetri_fts.c

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LBFT_PATH)
	@$(CC) -o $(NAME) $(OBJ) -lm -L $(LBFT_PATH) -lft

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<

.PHONY: all, $(NAME), clean, fclean, re

clean:
	@make -C $(LBFT_PATH) clean
	@rm -rf $(OBJ_PATH)

fclean: clean
	@make -C $(LBFT_PATH) fclean
	@rm -rf $(NAME)

re: fclean all
