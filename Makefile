SRCS	= utils/ft_printf_utils.c utils/ft_printf_arg.c utils/ft_printf_display.c flags/ft_printf_c.c flags/ft_printf_s.c flags/ft_printf_p.c flags/ft_printf_d.c  flags/ft_printf_prc.c ft_printf.c 
OBJS	= ${SRCS:.c=.o}
NAME	= libftprintf.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM = rm -f

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY:	all clean fclean re