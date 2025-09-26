SRCS =		$(wildcard src/*.c)

OBJS	=	$(SRCS:.c=.o)
NAME	=	philo

CC		=	cc
RM		=	rm -f
CFLAGS	=	-g -Wall -Wextra -Werror

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