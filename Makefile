# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alarose <alarose@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/23 15:39:00 by alarose           #+#    #+#              #
#    Updated: 2024/05/24 15:23:30 by alarose          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCDIR = ./
SRC =	ft_printf.c			\
		ft_printf_utils.c	\

BONUSDIR = ./
BONUS = #ft_printf_bonus.c			\
		ft_printf_utils_bonus.c		\

SRCS = $(addprefix $(SRCDIR), $(SRC))
BONUS_FILES = $(addprefix $(BONUSDIR), $(BONUS))
HEADERS_PATH = ./
HEADERS = -I $(HEADERS_PATH)
CC = gcc
OBJ = $(SRCS:.c=.o)
OBJ_BONUS = $(BONUS_FILES:.c=.o)
CFLAGS = -Wall -Wextra -Werror
AR = ar rc

all : $(OBJ)
	$(AR) ${NAME} ${OBJ}

%.o : %.c
	$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

$(NAME) : $(OBJ)
	$(AR) $@ $^

clean :
	/bin/rm -f $(OBJ)
	/bin/rm -f $(OBJ_BONUS)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all

#bonus : $(OBJ) ${OBJ_BONUS}
#	$(AR) ${NAME} ${OBJ} ${OBJ_BONUS}

.PHONY: all clean fclean re bonus