SRCS =		src/inits.c \
			src/main.c \
			src/monitor.c \
			src/normalization.c \
			src/philo.c \
			src/thread.c \
			src/utils.c \
			src/validation.c

OBJS	=	$(SRCS:.c=.o)
NAME	=	philo

CC		=	cc
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean	all