/*
** listPhilosophe.c for  in /home/atraxys/workspace/epitech/year_2/PSU_2016_philo/src/
**
** Made by Philippe Lefevre
** Login   <philippe1.lefevre@epitech.eu>
**
** Started on  Wed Mar  8 10:57:57 2017 Philippe Lefevre
** Last update	Wed Mar 15 16:58:18 2017 Philippe Lefevre
*/

#include	"philosophe.h"

t_philosophe	*createNode(enum e_state state, unsigned int eat_occur)
{
  t_philosophe	*new_node;

  if (((new_node = malloc(sizeof(t_philosophe))) == NULL)
      || ((new_node->own = malloc(sizeof(*new_node->own))) == NULL)
      || (pthread_mutex_init(new_node->own, NULL) != 0))
    return (NULL);
  new_node->state = state;
  new_node->eat_occur = eat_occur;
  new_node->next = new_node;
  new_node->prev = new_node;
  return (new_node);
}

t_philosophe	*addNode(t_philosophe *list,
			 enum e_state state,
			 unsigned int eat_occur)
{
  t_philosophe	*new;
  t_philosophe	*tmp;

  if (list == NULL)
    {
      if ((new = createNode(state, eat_occur)) == NULL)
	return (NULL);
      return (new);
    }
  tmp = list;
  if ((new = createNode(state, eat_occur)) == NULL)
    return (NULL);
  while (tmp->next != list)
    tmp = tmp->next;
  tmp->next = new;
  new->prev = tmp;
  new->next = list;
  list->prev = new;
  return (list);
}

void		showList(t_philosophe *philosophe)
{
  t_philosophe	*tmp;
  unsigned int	i;

  tmp = philosophe;
  i = 0;
  while (tmp->next != philosophe || i == 0)
    {
      ++i;
      printf("Philosophe %d still %d eat occurence ; state %s\n",
	     i, tmp->eat_occur, ((tmp->state == REST) ? ("REST")
				 : ((tmp->state == EAT) ? ("EAT")
				    : ((tmp->state == THINK) ? ("THINK")
				       : "UNDIFINED"))));
      tmp = tmp->next;

    }
}

void		freeList(t_philosophe *philosophe)
{
  t_philosophe	*tmp;
  t_philosophe	*to_free;

  tmp = philosophe;
  while (tmp->next != philosophe)
    {
      to_free = tmp;
      tmp = tmp->next;
      free(to_free->own);
      free(to_free);
    }
  free(tmp->own);
  free(tmp);
}
