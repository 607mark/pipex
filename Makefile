NAME = pipex

SRCS =  pipex.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -g

LIBFT_DIR = ./libft
FT_PRINTF_DIR = $(LIBFT_DIR)/ft_printf
LIBFT = -L$(LIBFT_DIR) -lft


# Default target
all: $(NAME)

# Build the executable
$(NAME): $(OBJS) $(LIBFT_DIR)/libft.a
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)

# Compile libft and ft_printf
$(LIBFT_DIR)/libft.a:
	@$(MAKE) -C $(FT_PRINTF_DIR) all
	@$(MAKE) -C $(LIBFT_DIR) all
	@touch $(LIBFT_DIR)/libft.a

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(FT_PRINTF_DIR) clean

# Clean all, including the executable
fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean

# Rebuild the project
re: fclean all

.PHONY: all clean fclean re
