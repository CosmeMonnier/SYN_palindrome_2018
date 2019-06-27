NAME	= palindrome
CC	= gcc

RM	= rm -f

SRCS	= ./src/baser.c \
	  ./src/dec_error.c \
	  ./src/palib.c \
	  ./src/palindrome.c 

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
