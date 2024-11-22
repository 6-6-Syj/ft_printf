NAME = libftprintf.a

SRCS =	ft_idk.c		\
		ft_putsmtg.c	\
		ft_printf.c		\

OBJS = $(SRCS:.c=.o)

CC = cc
FLAGS = -Wall -Werror -Wextra
RM = rm -f
HEADER = ft_printf.h
AR = ar
ARFLAGS = -r -c -s

all : $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
