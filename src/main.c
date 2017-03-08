/*
** main.c for  in /home/atraxys/workspace/epitech/year_2/PSU_2016_philo/src/
**
** Made by Philippe Lefevre
** Login   <philippe1.lefevre@epitech.eu>
**
** Started on  Wed Mar  8 09:35:54 2017 Philippe Lefevre
** Last update	Wed Mar 08 11:38:49 2017 Full Name
*/

#include	"extern.h"
#include	"philosophe.h"

void		initArg(char **av, unsigned int *nb_philosophe,
			unsigned int *nb_eat_occur)
{
  unsigned int	i;

  i = 0;
  while (av[++i])
    if (strlen(av[i]) == 2)
      {
	if (av[i][0] == '-' && av[i][1] == 'p')
	  {
	    *nb_philosophe = (av[i + 1] && is_num(av[i + 1])) ? (atoi(av[i + 1])) : (0);
	    if ((*nb_philosophe == 0) && (av[i + 1]))
	      fprintf(stderr, "Error: Invalid number of philosopher\n");
	    if ((*nb_philosophe == 0) && !(av[i + 1]))
	      fprintf(stderr, "Error: %s as no value\n", av[i]);
	  }
	else if (av[i][0] == '-' && av[i][1] == 'e')
	  {
	    *nb_eat_occur = (av[i + 1] && is_num(av[i + 1])) ? (atoi(av[i + 1])) : (0);
	    if ((*nb_eat_occur == 0) && (av[i + 1]))
	      fprintf(stderr, "Error: Invalid number of eat occurence\n");
	    if ((*nb_eat_occur == 0) && !(av[i + 1]))
	      fprintf(stderr, "Error: %s as no value\n", av[i]);
	  }
	else if (!(is_num(av[i])))
	  fprintf(stderr, "Error: Unkown option %s\n", av[i]);
      }
}

t_philosophe	*initPhilosophe(char **av)
{
  t_philosophe	*philosophe;
  unsigned int	nb_philosophe;
  unsigned int	nb_eat_occur;
  unsigned int 	i;

  initArg(av, &nb_philosophe, &nb_eat_occur);
  if ((nb_philosophe == 0) || (nb_eat_occur == 0))
    return (NULL);
  philosophe = NULL;
  i = 0;
  while (++i <= nb_philosophe)
    {
      printf("Creation du philosophe numero %d\n", i);
      philosophe = addNode(philosophe, UNDIFINED, nb_eat_occur);
    }
  return (philosophe);
}

int             main(int ac, char **av)
{
  t_philosophe	*philosophe;

  if (ac >= 5)
    {
      /*RCFStartup(ac, av);*/
      if ((philosophe = initPhilosophe(av)) == NULL)
	return (ERROR);
      showList(philosophe);
      freeList(philosophe);
      /*RCFCleanup();*/
    }
  return (SUCCESS);
}
