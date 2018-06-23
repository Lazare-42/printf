NAME = printf_test

SOURCES = get_modifiers.c \
		  ft_printf.c \
		  get_hex_adr.c \
		  list_management.c \
		  precision_width.c \
		  print.c \
		  set_get_static_var.c \
		  test.c \
		  treat_and_store_argument.c \
		  width_padding.c \

LIBDIR = libft
SDIR = srcs
ODIR = bin
CFLAGS = -Wall -Wextra -Werror
INCDIR = includes
LDFLAGS = -L$(LIBDIR) -lft
LNCURSES = -lncurses
CC = clang
SRCS = $(addprefix $(SDIR)/, $(SOURCES:.c=.c))
OBJS = $(addprefix $(ODIR)/, $(SOURCES:.c=.o))
OK = echo "[32m OK ✓ [0m"

all: lib mkbin $(NAME)

lib:
	@make -C $(LIBDIR)

mkbin:
	@mkdir -p $(ODIR)


$(NAME): $(OBJS)
	@ echo "[35m Entering Printf Makefile...[0m"
	@$(CC) $(CFLAGS)  -o $(NAME) $(OBJS) -I$(INCDIR) $(LDFLAGS) $(LNCURSES)
	@$(OK)

$(ODIR)/%.o : $(SDIR)/%.c
	@ echo "[34m Assembling Fract'ol object: [0m" $@
	@ $(CC) $(CFLAGS) -c -o $@ $< -I$(INCDIR)

clean:
	@ echo "[31m Cleaning Fract'ol... [0m"
	@/bin/rm -rf $(ODIR)
	@make -C $(LIBDIR) clean

fclean: clean
	@/bin/rm -rf $(NAME)
	@make -C $(LIBDIR) fclean

re: fclean all
