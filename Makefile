# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/15 23:46:57 by gpiccion          #+#    #+#              #
#    Updated: 2022/08/26 22:28:26 by gpiccion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##############		VARIABLES		##############

NAME 					= libftprintf.a
CC						= cc
CFLAGS					= -Wall -Wextra -Werror
INCLUDES				= -I ./includes/
LIBFT_DIR				= libft/
LIBFT_A					= $(LIBFT_DIR)libft.a

SRC						= ft_printf.c format_eval.c conversions.c conversions2.c auxiliary.c auxiliary2.c auxiliary3.c

OBJ						= $(SRC:.c=.o)

##############		RULES		##############

all:					$(NAME) bonus

mandatory:				$(NAME)

$(NAME):				$(LIBFT_A) $(OBJ)
						ar rcs $(NAME) $(OBJ) $(LIBFT_DIR)*.o

$(LIBFT_A):	
						make -C $(LIBFT_DIR)

%.o:					%.c
						$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
						rm -f $(OBJ)
						make clean -C $(LIBFT_DIR)

fclean:					clean
						rm -f $(NAME)
						make fclean -C $(LIBFT_DIR)

re:						fclean all

.PHONY: all  clean fclean re