# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyork <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/22 09:02:39 by kyork             #+#    #+#              #
#    Updated: 2016/10/11 11:29:33 by kyork            ###   ########.fr        #
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

FILENAMES	+= ft_strequ.c ft_strnequ.c
TESTS		+=

FILENAMES	+= ft_memmove.c ft_memcpy.c ft_memccpy.c ft_memcmp.c
TESTS		+= memmove memcpy memccpy memcmp

FILENAMES	+= ft_strstr.c ft_memchr.c ft_strchr.c ft_strrchr.c
FILENAMES	+= ft_strnstr.c
TESTS		+= strstr memchr           strchr

FILENAMES	+= ft_strcat.c ft_strncat.c ft_strlcat.c
TESTS		+= strcat strncat strlcat

FILENAMES	+= ft_strjoin.c
TESTS		+= strjoin

FILENAMES	+= ft_strsub.c
TESTS		+= strsub

FILENAMES	+= ft_strsplit.c ft_strtrim.c
TESTS		+= split strtrim

# need tests
FILENAMES	+= ft_memset.c ft_bzero.c ft_strnew.c ft_memalloc.c ft_strdup.c ft_memdel.c
FILENAMES	+= ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c

FILENAMES	+= ft_putchar_uni_fd.c
TESTS		+= unicode

TESTS		+= quentin yachaka

FILENAMES	+= ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c
FILENAMES	+= ft_lstiter.c ft_lstmap.c
TESTS		+= lstdel

FILENAMES	+= ft_lstpop.c ft_memdup.c

FILENAMES	+= ft_ary_create.c ft_ary_viewof.c ft_ary_set.c ft_ary_get.c
FILENAMES	+= ft_ary_grow.c ft_ary_append.c ft_ary_insert.c ft_ary_remove.c
FILENAMES	+= ft_ary_clear.c ft_ary_destroy.c ft_ary_swap.c
FILENAMES	+= ft_ary_remove_mul.c ft_ary_destroy2.c
TESTS		+= ary

NAME		= libft.a
CC			= gcc

CFLAGS		+= -Wall -Wextra -Wfloat-equal -Wundef -Werror -fverbose-asm -Wint-to-pointer-cast -Wshadow -Wpointer-arith -Wcast-align -Wstrict-prototypes -Wmissing-prototypes -Wstrict-overflow=5 -Wwrite-strings -Wconversion --pedantic-errors -std=gnu11
LDFLAGS		+= -Wall -Wextra -Wfloat-equal -Wundef -Werror -fverbose-asm -Wint-to-pointer-cast -Wshadow -Wpointer-arith -Wcast-align -Wstrict-prototypes -Wmissing-prototypes -Wstrict-overflow=5 -Wwrite-strings -Wconversion --pedantic-errors -std=gnu11

CFLAGS		+= -Iincludes/

ifeq ($(DEBUG), 1)
	#CFLAGS	+= -fsanitize=address
	#LDFLAGS	+= -fsanitize=address
else
	#CFLAGS	+= -O3 -fomit-frame-pointer -DNDEBUG -flto
	#LDFLAGS	+= -O3 -fomit-frame-pointer -DNDEBUG -flto
endif

ifdef ALLOCWRAP
	LDFLAGS += alloc_wrap.c -DHAVE_ALLOCWRAP
	CFLAGS	+= -DHAVE_ALLOCWRAP
endif

ifdef ONLY
	TESTS2 = $(filter $(ONLY), $(TESTS))
else
	TESTS2 = $(TESTS)
endif

SRCS	= $(FILENAMES)
OBJS	= $(addprefix build/, $(FILENAMES:.c=.o))

TESTTARGETS	= $(addprefix test-, $(TESTS2))
TESTBINS	= $(addprefix build/, $(TESTTARGETS))

.PHONY: all clean fclean re test

all: $(NAME)

re: fclean all

clean:
	rm -rf build/
	rm -f $(TESTBINS)

fclean: clean
	rm -f $(NAME)

build:
	mkdir build/

flags:
	echo DEBUG SKIP_LIST SKIP_KANE ALLOCWRAP ONLY[test]

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

norm:
	norminette $(SRCS) libft.h | grep -e 'Warning' -e 'Error' -B1 || true

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

build/test_quentin.o: test_quentin.c libft.h | build
	$(CC) $(CFLAGS) -I. -c $< -o $@

