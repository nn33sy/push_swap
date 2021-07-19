NAME = push_swap.a
CC=gcc
CFLAGS=  -Wall -Wextra -Werror
OBJ = ${SRCS:.c=.o}

SRCS =		ft_parsing.c\
			ft_utils.c\
			ft_sort_int_tab.c\
			ft_swap.c\
			ft_push.c\
			ft_rotate.c\
			ft_rrotate.c\
			ft_solve.c\
			ft_mediane.c\
			ft_atoi_ps.c\
			ft_sort_a.c\
			ft_insert.c\
			ft_five_hundred.c\
			ft_sort_five.c\
			ft_sort_five_bis.c\
			ft_parsing2.c
		
OBJS	=	$(SRCS:.c=.o)
# COLORS
C_NO	=	"\033[00m"
C_OK	=	"\033[35m"
C_GOOD	=	"\033[32m"
C_ERROR	=	"\033[31m"
C_WARN	=	"\033[33m"

# DBG MESSAGE
SUCCESS	=	$(C_GOOD)SUCCESS$(C_NO)
OK		=	$(C_OK)OK$(C_NO)

all: $(NAME)

%.o: %.c
		@$(CC) -Iincludes $(CFLAGS)  -c $< -o $@
		@echo "Linking" [ $< ] $(OK)
	
$(NAME): $(OBJ)
	@make re -C libft/
	@cp libft/libft.a ./$(NAME)
	@ar rc $@ $^
	@echo "Compiling & indexing" [ $(NAME) ] $(SUCCESS)
	@$(CC) -Iincludes  $(OBJ) $(CFLAGS)  main.c  $(NAME) libft/libft.a  -o  push_swap


clean:
	@make clean -C libft/
	@/bin/rm -f $(OBJ)
	@echo "[ft_printf] Removed object files!\n"

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f push_swap
	@make fclean -C libft/
	@echo "Cleaning" [ $(NAME) ] $(OK)

re: fclean all 

.PHONY: all clean fclean re 