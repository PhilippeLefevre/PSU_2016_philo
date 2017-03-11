/*
** philosophe.h for  in /home/atraxys/workspace/epitech/year_2/PSU_2016_philo/inc/
**
** Made by Philippe Lefevre
** Login   <philippe1.lefevre@epitech.eu>
**
** Started on  Wed Mar  8 09:51:22 2017 Philippe Lefevre
** Last update	Sat Mar 11 03:56:52 2017 Philippe Lefevre
*/

#ifndef	PHILOSOPHE_H_
# define PHILOSOPHE_H_

# include		<stdlib.h>
# include		<stdio.h>
# include		<string.h>
# include		<pthread.h>
# include		<unistd.h>
# include		"extern.h"

# define		SUCCESS	0
# define		ERROR	1

enum			e_cycle {
  UNDIFINED = -1,
  REST = 0,
  EAT,
  THINK
};

typedef struct		s_philosophe
{
  enum e_cycle		cycle;
  unsigned int		eat_occur;
  unsigned int		id;
  pthread_mutex_t	*own;
  pthread_mutex_t	*stolen;
  struct s_philosophe	*next;
  struct s_philosophe	*prev;
}			t_philosophe;

void			initArg(char **av, unsigned int *nb_philosophe,
				unsigned int *nb_eat_occur);
t_philosophe		*initPhilosophe(unsigned int *nb_philosophe, char **av);
int			is_num(char *s);
t_philosophe		*createNode(enum e_cycle cycle, unsigned int eat_occur);
t_philosophe		*addNode(t_philosophe *list,
				 enum e_cycle cycle,
				 unsigned int eat_occur);
void			doTable(unsigned int nb_philosophe,
				t_philosophe *philosophe);
void			showList(t_philosophe *philosophe);
void			freeList(t_philosophe *philosophe);

#endif /* !PHILOSOPHE_H_ */
