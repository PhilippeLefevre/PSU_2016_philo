/*
** table.c for  in /home/atraxys/workspace/epitech/year_2/PSU_2016_philo/src/
**
** Made by Philippe Lefevre
** Login   <philippe1.lefevre@epitech.eu>
**
** Started on  Thu Mar  9 16:35:25 2017 Philippe Lefevre
** Last update	Wed Mar 15 14:46:24 2017 Philippe Lefevre
*/

#include	"philosophe.h"

static int	haveFullyeat(t_philosophe *philosophe)
{
  t_philosophe	*tmp;

  tmp = philosophe;
  while (tmp->next != philosophe)
    {
      if (tmp->start == UNREADY)
	return (1);
      tmp = tmp->next;
    }
  if (tmp->start == UNREADY)
    return (1);
  return (0);
}
/*
static int	waitStart(t_philosophe *philosophe)
{
  t_philosophe	*tmp;

  tmp = philosophe;
  while (tmp->next != philosophe)
    {
      if (tmp->eat_occur == 0)
	return (1);
      tmp = tmp->next;
    }
  if (tmp->eat_occur == 0)
    return (1);
  return (0);
}
*/
static void	doCycle(t_philosophe *philosophe)
{
  if (philosophe->state == EAT)
    {
      while (pthread_mutex_trylock(philosophe->stolen) == 0);
      lphilo_take_chopstick(philosophe->stolen);
      lphilo_eat();
      philosophe->eat_occur--;
      lphilo_release_chopstick(philosophe->stolen);
      pthread_mutex_unlock(philosophe->stolen);
      philosophe->state = REST;
    }
  else if (philosophe->state == REST)
    {
      pthread_mutex_unlock(philosophe->own);
      lphilo_release_chopstick(philosophe->own);
      lphilo_sleep();
      while (pthread_mutex_trylock(philosophe->own) == 0);
      lphilo_take_chopstick(philosophe->own);
      philosophe->state = THINK;
    }
  else
    {
      lphilo_think();
      philosophe->state = EAT;
    }
}

static void	*doPhilosophe(void *p)
{
  t_philosophe	*philosophe;

  philosophe = p;
  philosophe->start = READY;
  pthread_mutex_trylock(philosophe->own);
  lphilo_take_chopstick(philosophe->own);
  while (philosophe->eat_occur != 0)
    {
      /*if (haveFullyeat(philosophe))
	pthread_exit(NULL);*/
      if (philosophe->eat_occur > 0)
	doCycle(philosophe);
    }
  pthread_exit(NULL);
}

void		doTable(unsigned int nb_philosophe, t_philosophe *philosophe)
{
  t_philosophe	*tmp;
  pthread_t	thread_id[nb_philosophe];
  unsigned int	i;

  i = 0;
  tmp = philosophe;
  while (tmp->next != philosophe)
    {
      if (pthread_create(&thread_id[i], NULL, doPhilosophe, (void *)tmp))
	exit(fprintf(stderr, "Error: cannot create thread\n") - 1);
      i++;
      tmp = tmp->next;
    }
  if (pthread_create(&thread_id[i], NULL, doPhilosophe, (void *)tmp))
    exit(fprintf(stderr, "Error: cannot create thread\n") - 1);
  i = -1;
  while (++i < nb_philosophe)
    pthread_join(thread_id[i], NULL);
}
