/*
** philosophe.h for  in /home/atraxys/workspace/epitech/year_2/PSU_2016_philo/inc/
**
** Made by Philippe Lefevre
** Login   <philippe1.lefevre@epitech.eu>
**
** Started on  Wed Mar  8 09:51:22 2017 Philippe Lefevre
** Last update	Thu Mar 09 16:15:11 2017 Full Name
*/

#ifndef	PHILOSOPHE_H_
# define PHILOSOPHE_H_

# include		<stdlib.h>
# include		<stdio.h>
# include		<string.h>
# include		<pthread.h>
# include		<unistd.h>

# define		SUCCESS	0
# define		ERROR	1

enum			e_cycle {
  UNDIFINED = -1,
  REST = 0,
  EAT,
  THINK
};

enum			e_chopstick {
  RELEASE = 0,
  TAKE
};

typedef struct		s_philosophe
{
  int			first;
  enum e_cycle		cycle;
  enum e_chopstick	chopstick_left;
  enum e_chopstick	chopstick_right;
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
void			showList(t_philosophe *philosophe);
void			freeList(t_philosophe *philosophe);

#endif /* !PHILOSOPHE_H_ */
