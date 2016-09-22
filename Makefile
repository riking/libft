# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyork <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/22 09:02:39 by kyork             #+#    #+#              #
#    Updated: 2016/09/21 18:42:33 by kyork            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILENAMES	+= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c
FILENAMES	+= ft_toupper.c ft_tolower.c
TESTS		+= isstuff

FILENAMES	+= ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c
FILENAMES	+= ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
TESTS		+= putstuff
TESTS		+= putnbr

FILENAMES	+= ft_atoi.c
TESTS		+= atoi

FILENAMES	+= ft_strcpy.c ft_strncpy.c ft_strcmp.c ft_strncmp.c
TESTS		+= strcpy strncpy			strcmp strncmp

FILENAMES	+= ft_memmove.c ft_memcpy.c ft_memccpy.c
TESTS		+= memmove ft_memcpy memstuff

FILENAMES	+= ft_strstr.c
TESTS		+= strstr

FILENAMES	+= ft_strcat.c ft_strncat.c ft_strlcat.c
TESTS		+= strcat strncat strlcat

FILENAMES	+= ft_strlcat.c ft_memset.c ft_bzero.c ft_memcmp.c
TESTS		+=
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

TESTTARGETS	= $(addprefix test-, $(TESTS))
TESTBINS	= $(addprefix build/, $(TESTTARGETS))

.PHONY: all clean fclean re test $(TESTTARGETS)

all: $(NAME)

re: fclean all

clean:
	rm -rf build/
	rm -f $(TESTBINS)

fclean: clean
	rm -f $(NAME)

build:
	mkdir build/

$(NAME): $(OBJS)
	ar rcs $@ $^

build/%.o: %.c libft.h | build
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TESTBINS)
	for bin in $(TESTBINS); do \
		echo $$bin ; \
		$$bin ; \
		echo ; \
	done

build/test-%: build/test_%.o libft.a | build
	$(CC) $(LDFLAGS) -o $@ $^

# Without ASan

build/ft_strcmp.o: ft_strcmp.c libft.h | build
	$(CC) $(filter-out -fsanitize=address,$(CFLAGS)) -c $< -o $@

build/ft_strncmp.o: ft_strncmp.c libft.h | build
	$(CC) $(filter-out -fsanitize=address,$(CFLAGS)) -c $< -o $@

build/test_strcmp.o: test_strcmp.c libft.h | build
	$(CC) $(filter-out -fsanitize=address,$(CFLAGS)) -c $< -o $@

build/test_strncmp.o: test_strncmp.c libft.h | build
	$(CC) $(filter-out -fsanitize=address,$(CFLAGS)) -c $< -o $@

build/test-strcmp: build/test_strcmp.o libft.a | build
	$(CC) $(filter-out -fsanitize=address,$(LDFLAGS)) -o $@ $^

build/test-strncmp: build/test_strncmp.o libft.a | build
	$(CC) $(filter-out -fsanitize=address,$(LDFLAGS)) -o $@ $^

