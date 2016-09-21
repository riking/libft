# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyork <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/22 09:02:39 by kyork             #+#    #+#              #
#    Updated: 2016/09/21 12:30:24 by kyork            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILENAMES	+= ft_memcpy.c 
TESTFILES	+= ft_memcpy.c

FILENAMES	+= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c
FILENAMES	+= ft_toupper.c ft_tolower.c
TESTFILES	+= isfoo.c

FILENAMES	+= ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c
FILENAMES	+= ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
TESTFILES	+= putstuff.c

FILENAMES	+= ft_atoi.c
TESTFILES	+=
NAME		= libft.a

CC		= gcc
CFLAGS	+= -Wall -Wextra -Werror
LDFLAGS	+= -Wall -Wextra -Werror

ifeq ($(DEBUG), 1)
	CFLAGS	+= -fsanitize=address
	LDFLAGS	+= -fsanitize=address
else
	#CFLAGS	+= -O3 -fomit-frame-pointer -DNDEBUG -flto
	#LDFLAGS	+= -O3 -fomit-frame-pointer -DNDEBUG -flto
endif

SRCS	= $(FILENAMES)
OBJS	= $(addprefix build/, $(FILENAMES:.c=.o))

TESTTARGETS	= $(addprefix test-, $(TESTFILES:.c=))

.PHONY: all clean fclean re test $(TESTTARGETS)

all: $(NAME)

re: fclean all

clean:
	rm -rf build/
	rm -f $(TESTS)

fclean: clean
	rm -f $(NAME)

build:
	mkdir build/

$(NAME): $(OBJS)
	ar rcs $@ $^

build/%.o: %.c libft.h | build
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TESTTARGETS)
	build/test-isfoo
	build/test-ft_memcpy
	build/test-putstuff

test-ft_memcpy: libft.a build/test_ft_memcpy.o | build
	$(CC) $(LDFLAGS) -o build/$@ $^

test-isfoo: libft.a build/test_isfoo.o | build
	$(CC) $(LDFLAGS) -o build/$@ $^

test-putstuff: libft.a build/test_putstuff.o | build
	$(CC) $(LDFLAGS) -o build/$@ $^

