# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyork <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/09 19:11:26 by kyork             #+#    #+#              #
#    Updated: 2016/10/21 21:53:24 by kyork            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

FILENAMES	+= do_printf.c ft_strichr.c printer.c strout.c
FILENAMES	+= parse_fmt.c parse_numflag.c
FILENAMES	+= out_chr.c out_dec.c out_base.c out_pct.c
FILENAMES	+= dprintf.c snprintf.c asprintf.c

OBJS		= $(addprefix build/, $(FILENAMES:.c=.o))

CFLAGS		+= -Wall -Wextra -Wmissing-prototypes
#CFLAGS		= -Wall -Wextra -Wfloat-equal -Wundef -Wint-to-pointer-cast -Wshadow -Wpointer-arith -Wcast-align -Wstrict-prototypes -Wcast-qual -Wmissing-prototypes -Wstrict-overflow=5 -Wwrite-strings -Wconversion --pedantic-errors
CFLAGS		+= -I includes/
LDFLAGS		+= -Wall -Wextra

DYNCALL_PATH	= ../extern/dyncall-0.9-release

ifndef NO_WERROR
	CFLAGS += -Werror
	LDFLAGS += -Werror
endif

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf build

fclean: clean
	rm -f $(NAME)

re: fclean all

build:
	mkdir -p build

build/%.o: srcs/%.c srcs/*.h | build
	$(CC) $(CFLAGS) -c -o $@ $<

smalltest: tests/small_test.c $(NAME) | build
	$(CC) $(CFLAGS) -c $< -o build/small_test.o
	$(CC) $(LDFLAGS) -o $@ build/small_test.o -L. -lftprintf

build/fuzz_main.o: tests/fuzz_main.c srcs/*.h | build
	$(CC) $(CFLAGS) -c $< -o build/small_test.o -I ../libft/includes -I $(DYNCALL_PATH)/include

fuzzmain: build/fuzz_main.o $(NAME) | build
	$(CC) $(LDFLAGS) -o $@ build/small_test.o -L. -lftprintf -L ../libft -lft -L $(DYNCALL_PATH)/lib -ldyncall_s
