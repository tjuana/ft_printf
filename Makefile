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

PROJECT_TEXT = $(C_BASIC)$(C_TX_MAGENTA)LIBS:     $(C_BASIC)\t
FLAGS = -Wall -Wextra -Werror

PRINTF_SRCS_NAME = ft_printf
PRINTF_SRCS_PATH = ./$(PRINTF_SRCS_NAME)/
PRINTF_SRCS_FILES = ft_printf.c 
PRINTF_SRCS = $(addprefix $(PRINTF_SRCS_PATH), $(PRINTF_SRCS_FILES))

PRINTF_OBJS_PATH = ./obj/
PRINTF_OBJS_FILES = $(PRINTF_SRCS_FILES:.c=.o)
PRINTF_OBJS = $(addprefix $(PRINTF_OBJS_PATH), $(PRINTF_OBJS_FILES))

INCLUDES = -I ./ft_printf -I ./libft -I ./inc
HEADERS_PATH = ./inc/
HEADERS_FILES = ft_printf.h libft.h
HEADERS = $(addprefix $(HEADERS_PATH), $(HEADERS_FILES))

all: $(NAME)

$(NAME): $(PRINTF_OBJS) $(HEADERS)
	@ar rc $(NAME) $(PRINTF_OBJS) $(LIB)
	@ranlib $(NAME)
	@echo " "
	@echo "\033[A\033[K\033[A"
	@echo "$(PROJECT_TEXT)Finished!"

$(PRINTF_OBJS_PATH)%.o: $(PRINTF_SRCS_PATH)%.c
	@/bin/echo -n "."
	@mkdir $(PRINTF_OBJS_PATH) 2>/dev/null || echo "" > /dev/null
	@gcc $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -fv $(PRINTF_OBJS) > /dev/null
	@rm -rf $(PRINTF_OBJS_PATH) > /dev/null

fclean: clean
	@rm -fv $(NAME) > /dev/null

re: fclean all

.PHONY: clean fclean re all