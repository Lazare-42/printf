NAME = Fract\'ol

SOURCES = main.c \
		  static_variables.c \
		  user_actions.c \
		  frames_per_seconds.c \
		  complexe_operations.c \
		  thread_management.c \
		  mouse_actions.c \
		  color_settings.c \
		  ./fractal_budhabrot.c \
		  ./fractal_burning_ship.c \
		  ./fractal_mandelbrot_julia.c \
		  ./fractal_square.c \


LIBDIR = libft
MINILIBXDIR = minilibx_macos
SDIR = srcs
ODIR = bin
CFLAGS = -Wall -Wextra -Werror
INCDIR = includes
LDFLAGS = -L$(LIBDIR) -lpthread -lft -L$(MINILIBXDIR) -lmlx -framework AppKit -framework OpenGL
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
	@ echo "[35m Entering Fract'ol Makefile...[0m"
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
