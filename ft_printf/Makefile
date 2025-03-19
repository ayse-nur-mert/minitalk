SRCS = ft_printf.c ft_utils1.c ft_utils2.c 

OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a
CC = cc
ARFLAGS = -rc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar $(ARFLAGS) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME) 

re: fclean all
