NAME = libftprintf.a

C_TX_BLACK = \033[30m
C_TX_RED = \033[31m
C_TX_GREEN = \033[32m
C_TX_YELLOW = \033[33m
C_TX_BLUE = \033[34m
C_TX_MAGENTA = \033[35m
C_TX_CYAN = \033[36m
C_TX_GREY = \033[37m

C_BG_BLACK = \033[40m
C_BG_RED = \033[41m
C_BG_GREEN = \033[42m
C_BG_YELLOW = \033[43m
C_BG_BLUE = \033[44m
C_BG_MAGENTA = \033[45m
C_BG_CYAN = \033[46m
C_BG_GREY = \033[47m

C_BASIC = \033[0m


FLAGS = gcc 

INC = include/printf.h libft/includes/libft.h

SRC = ft_printf.c

OBJ_DIR = ./obj/
OBJ_FILES = $(SRC:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

all: lib $(NAME)

$(OBJ): 
		mkdir -p $(OBJ_DIR)
		$(FLAGS) -c $(SRC) -I ./include 

$(NAME):	$(OBJ)
		$(FLAGS) $(OBJ) -I ./include -L ./libft/ -lft -o $(NAME)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

lib:
		make -C ./libft

clean:
		rm -rf $(OBJ)
		make -C ./libft clean

fclean: clean
		rm -f $(NAME)
		make -C ./libft fclean


re: fclean all

.PHONY: clean fclean re all