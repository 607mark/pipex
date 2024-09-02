# Source files for libft
SRCS =  ft_isalpha.c \
        ft_isdigit.c \
        ft_isalnum.c \
        ft_isascii.c \
        ft_isprint.c \
        ft_strlen.c \
        ft_memset.c \
        ft_bzero.c \
        ft_memcpy.c \
        ft_memmove.c \
        ft_strlcpy.c \
        ft_strlcat.c \
        ft_toupper.c \
        ft_tolower.c \
        ft_strchr.c \
        ft_strrchr.c \
        ft_strncmp.c \
        ft_memchr.c \
        ft_memcmp.c \
        ft_strnstr.c \
        ft_substr.c \
        ft_atoi.c \
        ft_calloc.c \
        ft_strdup.c \
        ft_strjoin.c \
        ft_strtrim.c \
        ft_split.c \
        ft_itoa.c \
        ft_strmapi.c \
        ft_striteri.c \
        ft_putchar_fd.c \
        ft_putstr_fd.c \
        ft_putendl_fd.c \
        ft_putnbr_fd.c

# Source files for libft bonus
SRCSB = ft_lstnew_bonus.c \
        ft_lstadd_front_bonus.c \
        ft_lstsize_bonus.c \
        ft_lstlast_bonus.c \
        ft_lstadd_back_bonus.c \
        ft_lstdelone_bonus.c \
        ft_lstclear_bonus.c \
        ft_lstiter_bonus.c \
        ft_lstmap_bonus.c

# Source files for ft_printf
SRCS_PRINTF = ft_printf/ft_printf.c \
              ft_printf/ft_printf_utils.c \
              ft_printf/format_specifier_funcs.c

# Source files for get_next_line
SRCS_GNL = get_next_line/get_next_line.c \
           get_next_line/get_next_line_utils.c

# Combine all source files
ALL_SRCS = $(SRCS) $(SRCSB) $(SRCS_PRINTF) $(SRCS_GNL)

# Compiler and flags
CC = cc
FLAGS = -Wall -Wextra -Werror

# Output archive name
NAME = libft.a

# Object files
OBJ = $(ALL_SRCS:.c=.o)

# Archive command
AR = ar rcs

# Default target
all: $(NAME)

# Build the library
$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

# Compile object files
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

# Bonus target
bonus: .bonus

.bonus: $(OBJ)
	$(AR) $(NAME) $(OBJ)
	@touch .bonus

# Remove object files
clean:
	rm -f $(OBJ)

# Remove object files and library
fclean: clean
	rm -f $(NAME)
	@rm -f .bonus

# Rebuild the project
re: fclean all

