# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyork <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/22 09:02:39 by kyork             #+#    #+#              #
#    Updated: 2016/09/22 12:23:34 by kyork            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILENAMES	+= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c
FILENAMES	+= ft_toupper.c ft_tolower.c
TESTS		+= isstuff

FILENAMES	+= ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c
FILENAMES	+= ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
TESTS		+= putstuff
FILENAMES	+= ft_itoa.c
TESTS		+= putnbr

FILENAMES	+= ft_atoi.c
TESTS		+= atoi

FILENAMES	+= ft_strcpy.c ft_strncpy.c ft_strcmp.c ft_strncmp.c ft_strlen.c
TESTS		+= strcpy strncpy			strcmp strncmp           strlen

FILENAMES	+= ft_memmove.c ft_memcpy.c ft_memccpy.c ft_memcmp.c
TESTS		+= memmove memcpy memccpy memcmp

FILENAMES	+= ft_strstr.c ft_memchr.c
TESTS		+= strstr memchr

FILENAMES	+= ft_strcat.c ft_strncat.c ft_strlcat.c
TESTS		+= strcat strncat strlcat

# need tests
FILENAMES	+= ft_memset.c ft_bzero.c ft_strnew.c ft_memalloc.c ft_strdup.c ft_memdel.c
FILENAMES	+= ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c
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

ifdef ONLY
	TESTS2 = $(filter $(ONLY), $(TESTS))
else
	TESTS2 = $(TESTS)
endif

ifdef ALLOCWRAP
	LDFLAGS += $(HOME)/server/42/alloc_check/alloc_wrap.c
endif

SRCS	= $(FILENAMES)
OBJS	= $(addprefix build/, $(FILENAMES:.c=.o))

TESTTARGETS	= $(addprefix test-, $(TESTS2))
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

