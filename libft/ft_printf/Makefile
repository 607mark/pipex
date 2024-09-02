# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 18:20:47 by mshabano          #+#    #+#              #
#    Updated: 2024/06/20 19:28:52 by mshabano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c \
       ft_printf_utils.c \
       format_specifier_funcs.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

# Default target
all: $(NAME)

# Build the library
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Remove object files
clean:
	rm -f $(OBJS)

# Remove object files and library
fclean: clean
	rm -f $(NAME)

# Rebuild the project
re: fclean all
