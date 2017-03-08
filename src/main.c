/*
** main.c for  in /home/atraxys/workspace/epitech/year_2/PSU_2016_philo/src/
**
** Made by Philippe Lefevre
** Login   <philippe1.lefevre@epitech.eu>
**
** Started on  Wed Mar  8 09:35:54 2017 Philippe Lefevre
** Last update	Wed Mar 08 19:34:39 2017 Full Name
*/

#include	"extern.h"
#include	"philosophe.h"

int		haveFullyeat(t_philosophe *philosophe)
{
  t_philosophe	*tmp;

  tmp = philosophe;
  while (tmp != NULL)
    {
      if (tmp->eat_occur == 0)
	return (1);
      tmp = tmp->next;
    }
  if (tmp->eat_occur == 0)
    return (1);
  return (0);
}

void		*doPhilosophe(void *p)
{
  t_philosophe	*philosophe;
  unsigned int	i;
  pthread_mutex_t		mutex = PTHREAD_MUTEX_INITIALIZER;
  philosophe = p;

  fprintf(stderr, "thread successfully created for philosophe %d\n", philosophe->id);
  if (philosophe->cycle == EAT)
    {
      pthread_mutex_trylock(&mutex);
      lphilo_take_chopstick(&mutex);
      lphilo_eat();
      pthread_mutex_unlock(&mutex);
    }
  else
    lphilo_sleep();

  /*while (philosophe->eat_occur != 0);*/
    if (philosophe->eat_occur == 0)
	{
	  exit(0);
	}
    sleep(5);
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
	exit(fprintf(stderr, "Error: can not create thread\n") - 1);
      i++;
      tmp = tmp->next;
    }
  if (pthread_create(&thread_id[i], NULL, doPhilosophe, (void *)tmp))
    exit(fprintf(stderr, "Error: can not create thread\n") - 1);
  i = -1;
  while (++i < nb_philosophe)
    pthread_join(thread_id[i], NULL);
}

int             main(int ac, char **av)
{
  t_philosophe	*philosophe;
  unsigned int	nb_philosophe;


  RCFStartup(ac, av);
  if ((philosophe = initPhilosophe(&nb_philosophe, av)) == NULL)
    return (ERROR);
  showList(philosophe);
  doTable(nb_philosophe, philosophe);
  freeList(philosophe);
  RCFCleanup();
  return (SUCCESS);
}
