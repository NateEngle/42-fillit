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

INC_NAME = header.hh

SRC_NAME = main.c block.c file_reader.c map_fcts.c solve_file.c get_piece.c

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
