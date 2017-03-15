##
## Makefile for  in /home/atraxys/workspace/epitech/year_2/PSU_2016_philo/
##
## Made by Philippe Lefevre
## Login   <philippe1.lefevre@epitech.eu>
##
## Started on  Wed Mar  8 09:30:40 2017 Philippe Lefevre
## Last update Wed Mar 15 14:45:49 2017 Philippe Lefevre
##

NAME		=	philo

CC		=	gcc
CFLAGS		=	-W -Wextra -Wall -pedantic -ansi -std=gnu99
#CFLAGS		+=	-Werror
CFLAGS		+=	-Iinc

LDFLAGS		=	-Llib -lriceferee -lpthread

SRC		=	src/main.c \
			src/init.c \
			src/utils.c \
			src/table.c \
			src/listPhilosophe.c

OBJ		=	$(SRC:.c=.o)

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			@$(CC) $(OBJ) $(LDFLAGS) -o $(NAME) && \
			printf "[\033[1;36mbuilt\033[0m] % 32s\n" $(NAME) | tr ' ' '.' || \
			printf "[\033[1;31mfailed\033[0m] % 31s\n" $(NAME) | tr ' ' '.'

.c.o		:
			@$(CC) $(CFLAGS) $(LDFLAG) -c $< -o $@ && \
			printf "[\033[1;32mcompiled\033[0m] % 29s\n" $< | tr ' ' '.' || \
			printf "[\033[1;31mfailed\033[0m] % 31s\n" $< | tr ' ' '.'
clean		:
			@$(RM) $(OBJ) && \
			printf "[\033[1;31mdeleted\033[0m] % 30s\n" $(OBJ) | tr ' ' '.' || \
			printf "[\033[1;31mdeleted\033[0m] % 30s\n" $(OBJ) | tr ' ' '.'

fclean		:	clean
			@$(RM) $(NAME) && \
			printf "[\033[1;31mdeleted\033[0m] % 30s\n" $(NAME) | tr ' ' '.' || \
			printf "[\033[1;31mdeleted\033[0m] % 30s\n" $(NAME) | tr ' ' '.'

re		:	fclean all

.PHONY		:	all clean fclean re
