
## Makefile for compile in /home/munoz_d/rendu/Piscine_C_infinadd
## 
## Made by munoz david
## Login   <munoz_d@epitech.net>
## 
## Started on  Tue Oct 20 22:58:53 2015 munoz david
## Last update Thu Nov  5 14:34:12 2015 loic durand
##

SRC     = 101pong.c

OBJ     = $(SRC:.c=.o)

NAME    = 101pong

RM      = rm -f

CC      = gcc 

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lm

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

