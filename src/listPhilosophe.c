/*
** listPhilosophe.c for  in /home/atraxys/workspace/epitech/year_2/PSU_2016_philo/src/
**
** Made by Philippe Lefevre
** Login   <philippe1.lefevre@epitech.eu>
**
** Started on  Wed Mar  8 10:57:57 2017 Philippe Lefevre
** Last update	Wed Mar 08 11:39:56 2017 Full Name
*/

#include	"philosophe.h"

t_philosophe	*createNode(enum e_cycle cycle, unsigned int eat_occur)
{
  t_philosophe	*new_node;

  if ((new_node = malloc(sizeof(t_philosophe))) == NULL)
    return (NULL);
  new_node->cycle = cycle;
  new_node->eat_occur = eat_occur;
  new_node->next = NULL;
  return (new_node);
}

t_philosophe	*addNode(t_philosophe *list,
			 enum e_cycle cycle,
			 unsigned int eat_occur)
{
  t_philosophe	*new;
  t_philosophe	*tmp;

  if (list == NULL)
    {
      if ((new = createNode(cycle, eat_occur)) == NULL)
	return (NULL);
      return (new);
    }
  tmp = list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  if ((new = createNode(cycle, eat_occur)) == NULL)
    return (NULL);
  tmp->next = new;
  return (list);
}

void		showList(t_philosophe *philosophe)
{
  t_philosophe	*tmp;
  unsigned int	i;

  tmp = philosophe;
  i = 0;
  while (tmp != NULL)
    {
      ++i;
      printf("Philosophe %d still %d eat occurence ; cycle %d\n", i, tmp->eat_occur, tmp->cycle);
      tmp = tmp->next;

    }
}

void		freeList(t_philosophe *philosophe)
{
  t_philosophe	*tmp;
  t_philosophe	*to_free;

  tmp = philosophe;
  while (tmp != NULL)
    {
      to_free = tmp;
      tmp = tmp->next;
      free(to_free);
    }
}
