CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME =  libftprintf.a
RM = rm -f
AR = ar rcs

SRC = ft_putnbr_usigned.c ft_printf.c cherche_indicateur.c  ft_putchar.c\
	ft_strchr.c ft_putstr.c ft_putnbr.c\
	ft_putnbr_hex_mj.c ft_putpointer.c ft_putnbr_hex.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
