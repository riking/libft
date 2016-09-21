# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyork <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/22 09:02:39 by kyork             #+#    #+#              #
#    Updated: 2016/09/21 09:22:42 by kyork            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILENAMES	= 
FILENAMES	+= 
NAME		= libft.a

CC		= gcc
CFLAGS	+= -Wall -Wextra -Werror
LDFLAGS	:= $(CFLAGS)

ifeq ($(DEBUG), 1)
	CFLAGS += -fsanitize=address
	LFLAGS += -fsanitize=address
else
	#CFLAGS += -O3 -fomit-frame-pointer -DNDEBUG -flto
	#LDFLAGS += -O3 -fomit-frame-pointer -DNDEBUG -flto
endif

SRCS	= $(FILENAMES)
OBJS	= $(addprefix build/, $(FILENAMES:.c=.o))

.PHONY: all clean fclean re

all: $(NAME)

re: fclean all

clean:
	rm -rf build/

fclean: clean
	rm -f $(NAME)

build:
	mkdir build/

$(NAME): $(OBJS)
	ar rcs $@ $^

build/%.o: %.c libft.h | build
	$(CC) $(CFLAGS) -c $< -o $@

