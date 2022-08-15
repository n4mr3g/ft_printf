# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/15 23:46:57 by gpiccion          #+#    #+#              #
#    Updated: 2022/08/15 23:52:11 by gpiccion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##############		VARIABLES		##############

NAME 					= libftprintf.a
CC						= cc
CFLAGS					= -Wall -Wextra -Werror
INCLUDES				= -I ./includes/
LIBFT_DIR				= libft/
LIBFT_A					= $(LIBFT_DIR)libft.a

SRC						= ft_printf.c format_eval.c conversions.c conversions2.c auxiliary.c auxiliary2.c
SRC_BONUS				= ft_printf_bonus.c format_eval_bonus.c \
						conversions_bonus.c conversions2_bonus.c \
						auxiliary_bonus.c auxiliary2_bonus.c auxiliary3_bonus.c

OBJ						= $(SRC:.c=.o)
OBJ_BONUS				= $(SRC_BONUS:.c=.o)

##############		RULES		##############

all:					$(NAME) bonus

mandatory:				$(NAME)

$(NAME):				$(LIBFT_A) $(OBJ)
						ar rcs $(NAME) $(OBJ) $(LIBFT_DIR)*.o

$(LIBFT_A):	
						make -C $(LIBFT_DIR)

%.o:					%.c
						$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus:					$(LIBFT_A) $(OBJ_BONUS)
						ar rcs $(NAME) $(OBJ_BONUS) $(LIBFT_DIR)*.o
clean:
						rm -f $(OBJ) $(OBJ_BONUS)
						make clean -C $(LIBFT_DIR)

fclean:					clean
						rm -f $(NAME)
						make fclean -C $(LIBFT_DIR)

re:						fclean all

.PHONY: all bonus clean fclean re