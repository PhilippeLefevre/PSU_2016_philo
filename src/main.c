/*
** main.c for  in /home/atraxys/workspace/epitech/year_2/PSU_2016_philo/src/
**
** Made by Philippe Lefevre
** Login   <philippe1.lefevre@epitech.eu>
**
** Started on  Wed Mar  8 09:35:54 2017 Philippe Lefevre
** Last update	Sat Mar 11 02:24:58 2017 Philippe Lefevre
*/

#include	"philosophe.h"

int             main(int ac, char **av)
{
  t_philosophe	*philosophe;
  unsigned int	nb_philosophe;

  RCFStartup(ac, av);
  if ((philosophe = initPhilosophe(&nb_philosophe, av)) == NULL)
    return (ERROR);
  doTable(nb_philosophe, philosophe);
  return (SUCCESS);
}
