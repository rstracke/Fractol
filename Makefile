CC			=	clang
NAME		=	fractol
FLAGS		=	-Wall -Wextra -Werror
FLAGSMX		=	-framework OpenGL -framework AppKit
FLAGSCL		=	-framework OpenCL
LIBS		=	libs

LFTDIR	=	$(LIBS)/libft
LFTLINK	=	-L $(LFTDIR) -lft
LFT		=	$(LFTDIR)/libft.a

LMATHDIR	=	$(LIBS)/libmath
LMATHLINK	=	-L $(LMATHDIR) -lmath
LMATH		=	$(LMATHDIR)/libmath.a

LMLXDIR	=	$(LIBS)/libmlx
LMLXLINK	=	-L $(LMLXDIR) -lmlx
LMLX		=	$(LMLXDIR)/libmlx.a

INCLUDES	=	-I ./includes
INCLUDE		=	./includes

OBJDIR		=	objs
SRCDIR		=	srcs
SRC			=	main.c\
				init.c\
				file.c\
				limits.c\
				fractol.c\
				key_events.c\
				mouse_events.c\
				rgb.c\
				utils.c\
				border.c\
				point.c\
				f_cl.c\
				f_cl_helper.c\
				f_cl_loader.c\
				mlx_graphics.c\
				mlx_pixel.c

OBJ			=	$(SRC:.c=.o)
SRCS		=	$(addprefix $(SRCDIR)/, $(SRC))
OBJS		=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))

all: directory $(NAME)

$(NAME): $(OBJDIR) $(OBJS) $(INCLUDE)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LMLXLINK) $(FLAGSMX) $(FLAGSCL) $(LFTLINK) $(LMATHLINK)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) -c $(FLAGS) $^ -o $@ $(INCLUDES)

directory: $(OBJDIR)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(OBJDIR)
fclean: clean
	@rm -rf $(NAME)

re:	fclean all
