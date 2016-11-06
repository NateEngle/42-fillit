NAME = fillit

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra

SRC_PATH = ./
INC_PATH = ./
OBJ_PATH = ./obj/
LBFT_PATH = ./libft/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
DELETE = $(OBJ)

OBJ_NAME = $(SRC_NAME:.c=.o)

INC_NAME = header.h

<<<<<<< HEAD
SRC_NAME = main.c
SRC_NAME = main.c change.c tetri_check.c new.c find_block.c 
=======
SRC_NAME = main.c change.c tetri_check.c new.c find_block.c fill_map.c
>>>>>>> dc5e01c1430c7c1f37c69f9b67b077e9b5f76efb

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
