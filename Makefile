
INC=%%%%

INCLIB=$(INC)/../lib

UNAME := $(shell uname)

CFLAGS= -I$(INC) -O3 -I.. -g

NAME= fdf
SRC = main.c read_file.c
OBJ = $(SRC:%.c=%.o)
LIBFT_DIRECTORY = ./libft/
LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBRARIES = -lft -L$(LIBFT_DIRECTORY)

#linux
#LFLAGS = -Lminilibx-linux -lmlx -L$(INCLIB) -lXext -lX11 -lm
#macos
LFLAGS = ${LIBRARIES} -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

ifeq ($(UNAME), Darwin)
	# mac
	CC = clang
else ifeq ($(UNAME), FreeBSD)
	# FreeBSD
	CC = clang
else
	#Linux and others...
	CC	= gcc
	LFLAGS += -lbsd
endif

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	make -C libft dop
	$(CC) -o $(NAME) $(OBJ) $(LFLAGS)

show:
	@printf "UNAME		: $(UNAME)\n"
	@printf "NAME  		: $(NAME)\n"
	@printf "CC		: $(CC)\n"
	@printf "CFLAGS		: $(CFLAGS)\n"
	@printf "LFLAGS		: $(LFLAGS)\n"
	@printf "SRC		:\n	$(SRC)\n"
	@printf "OBJ		:\n	$(OBJ)\n"

clean:
	make -C libft fclean
	rm -f $(NAME) $(OBJ) *~ core *.core

fclean: 	clean
			${RM} ${NAME}

re: clean all

#libft:
#	cd ${LIBFT_DIRECTORY} && make && make bonus && make dop && cd ..