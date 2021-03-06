/*
** init.c for  in /home/atraxys/workspace/epitech/year_2/PSU_2016_philo/src/
**
** Made by Philippe Lefevre
** Login   <philippe1.lefevre@epitech.eu>
**
** Started on  Wed Mar  8 16:48:31 2017 Philippe Lefevre
** Last update	Wed Mar 15 14:46:41 2017 Philippe Lefevre
*/

#include	"philosophe.h"

void		initArg(char **av, unsigned int *nb_philosophe,
			unsigned int *nb_eat_occur)
{
  unsigned int	i;
  int		len_arg;

  i = 0;
  while (av[++i])
    if (((len_arg = strlen(av[i])) == 2) && av[i][0] == '-' && av[i][1] == 'p')
      {
	*nb_philosophe = (av[i + 1]
			  && is_num(av[i + 1])) ? (atoi(av[i + 1])) : (0);
      }
    else if (len_arg == 2 && av[i][0] == '-' && av[i][1] == 'e')
      {
	*nb_eat_occur = (av[i + 1]
			 && is_num(av[i + 1])) ? (atoi(av[i + 1])) : (0);
      }
}

void		setRolestate(t_philosophe *philosophe)
{
  t_philosophe	*tmp;
  unsigned int	i;

  tmp = philosophe;
  i = 0;
  while (tmp != philosophe || i == 0)
    {
      ++i;
      if (i % 2)
	tmp->state = EAT;
      else
	tmp->state = REST;
      tmp->id = i;
      tmp->stolen = tmp->next->own;
      tmp = tmp->next;
    }
}

t_philosophe	*initPhilosophe(unsigned int *nb_philosophe, char **av)
{
  t_philosophe	*philosophe;
  unsigned int	nb_eat_occur;
  unsigned int 	i;

  *nb_philosophe = 0;
  nb_eat_occur = 0;
  initArg(av, nb_philosophe, &nb_eat_occur);
  if ((*nb_philosophe < 2) || (nb_eat_occur == 0))
    return (NULL);
  philosophe = NULL;
  i = 0;
  while (++i <= *nb_philosophe)
    philosophe = addNode(philosophe, THINK, nb_eat_occur);
  setRolestate(philosophe);
  return (philosophe);
}
