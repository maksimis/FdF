NAME = libft.a

SRCS = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isprint.c \
		ft_strlcpy.c ft_strlen.c ft_strdup.c ft_isdigit.c \
		ft_memset.c ft_bzero.c ft_atoi.c ft_calloc.c \
		ft_itoa.c ft_memcmp.c ft_memcpy.c ft_putchar_fd.c \
		ft_putendl_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
		ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strmapi.c \
		ft_strnstr.c ft_strtrim.c ft_substr.c ft_toupper.c \
		ft_tolower.c ft_putnbr_fd.c ft_strncmp.c ft_memchr.c \
		ft_memmove.c ft_strrchr.c

SRCS_B =	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
			ft_lstlast.c	ft_lstadd_back.c  ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c

SRCS_DOP = get_next_line.c get_next_line_utils.c

HEADER = libft.h

OBJS = ${SRCS:%.c=%.o}
OBJS_B = ${SRCS_B:%.c=%.o}
OBJS_DOP = ${SRCS_DOP:%.c=%.o}

CC = gcc
CFLAGS = -Wextra -Wall -Werror
RM = rm -rf

.PHONY: all clean fclean re bonus

%.o : %.c ${HEADER}
		 ${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

$(NAME): ${OBJS} ${HEADER}
		ar rcs ${NAME} $?

bonus:
	@make OBJS="${OBJS_B}" all

dop:
	@make OBJS="${OBJS_DOP}" all

clean:
	 @${RM} ${OBJS} ${OBJS_B} ${OBJS_DOP}

fclean: 	clean
			${RM} ${NAME}

re:	fclean all

all_dop: all dop

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS)