/*
** philosophe.h for  in /home/atraxys/workspace/epitech/year_2/PSU_2016_philo/inc/
**
** Made by Philippe Lefevre
** Login   <philippe1.lefevre@epitech.eu>
**
** Started on  Wed Mar  8 09:51:22 2017 Philippe Lefevre
** Last update	Wed Mar 08 12:56:37 2017 Full Name
*/

#ifndef	PHILOSOPHE_H_
# define PHILOSOPHE_H_

# include		<stdlib.h>
# include		<stdio.h>
# include		<string.h>

# define		SUCCESS	0
# define		ERROR	1

enum			e_cycle {
  UNDIFINED = -1,
  SLEEP = 0,
  EAT,
  THINK
};

enum			e_chopstick {
  TAKE = 0,
  RELEASE
};

typedef struct		s_philosophe
{
  enum e_cycle		cycle;
  enum e_chopstick	chopstick;
  unsigned int		eat_occur;
  struct s_philosophe	*next;
}			t_philosophe;

int			is_num(char *s);
t_philosophe		*createNode(enum e_cycle cycle, unsigned int eat_occur);
t_philosophe		*addNode(t_philosophe *list,
				 enum e_cycle cycle,
				 unsigned int eat_occur);
void			showList(t_philosophe *philosophe);
void			freeList(t_philosophe *philosophe);

#endif /* !PHILOSOPHE_H_ */
