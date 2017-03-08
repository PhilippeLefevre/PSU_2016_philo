##
## Makefile for  in /home/atraxys/workspace/epitech/year_2/PSU_2016_philo/
##
## Made by Philippe Lefevre
## Login   <philippe1.lefevre@epitech.eu>
##
## Started on  Wed Mar  8 09:30:40 2017 Philippe Lefevre
## Last update Wed Mar  8 12:40:08 2017 Philippe Lefevre
##

NAME		=	philo

CC		=	gcc
CFLAGS		=	-W -Wextra -Wall -pedantic -ansi
#CFLAGS		+=	-Werror
CFLAGS		+=	-Iinc

LDFLAGS		=	-Llib -lriceferee -lpthread

SRC		=	src/main.c			\
			src/utils.c			\
			src/listPhilosophe.c

OBJ		=	$(SRC:.c=.o)

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

clean		:
			$(RM) $(OBJ)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re
