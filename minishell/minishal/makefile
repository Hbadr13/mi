SRC_FILE	=	main.c to_path.c ft_split.c comd_existe.c if_absolute_path.c libft.c \
				mutiline_commands.c extract_cmd_and_cd.c cmd_echo.c
NAME		= minishell
OBJ_FILE	= $(SRC_FILE:.c=.o)
CFLAGS		= 
HEADER		= header/minishell.h
CC	   		= gcc  

GREEN  = \033[1;32m
YELLOW = \033[1;33m
all : $(NAME)

%.o:%.c $(HEADER)
	@${CC} $(CFLAGS)  -c $< -o $@

$(NAME) : $(OBJ_FILE)
	@$(CC) $(FLAGS)  $(OBJ_FILE) -o $(NAME) -lreadline
	@echo "$(GREEN)---> success!"
clean :
	@rm -f $(OBJ_FILE)
	@echo "${YELLOW}---> object files deleted!"
fclean : clean
	@rm -f $(NAME)
	@echo "${YELLOW}---> all deleted!"
re : fclean all

