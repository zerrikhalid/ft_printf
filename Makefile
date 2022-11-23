# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 13:40:49 by kzerri            #+#    #+#              #
#    Updated: 2022/11/24 00:03:52 by kzerri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = libftprintf.a

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

SRCS = ft_printf.c ft_printf_utiles.c ft_strchr.c
	
OBJ_M = $(SRCS:.c=.o)


$(NAME): $(OBJ_M) 
	$(AR) $(NAME) $(OBJ_M)

%o:%c ft_printf.h
	$(CC) $(CFLAGS) -c $<

all: $(NAME)

bonus: all

clean:
	$(RM) $(OBJ_M)

fclean: clean
		$(RM) $(NAME)

re: fclean bonus all