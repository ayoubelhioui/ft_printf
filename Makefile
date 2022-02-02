# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-hiou <ael-hiou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/28 11:39:54 by ael-hiou          #+#    #+#              #
#    Updated: 2021/11/30 11:43:46 by ael-hiou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
RM = rm -f
CLIB = ar rc
CFLAGS = -Wextra -Werror -Wall
SRC = ft_printf.c ft_printf_utils.c
NAME = libftprintf.a
OBJECTFILE = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTFILE)
	$(CLIB) $(NAME) $(OBJECTFILE)
clean:
	$(RM) $(OBJECTFILE)
fclean : clean
	$(RM) $(NAME)
re : fclean all