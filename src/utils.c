/*
** utils.c for  in /home/atraxys/workspace/epitech/year_2/PSU_2016_philo/src/
**
** Made by Philippe Lefevre
** Login   <philippe1.lefevre@epitech.eu>
**
** Started on  Wed Mar  8 10:58:41 2017 Philippe Lefevre
** Last update	Wed Mar 08 10:59:02 2017 Full Name
*/

#include	<stdio.h>

int		is_num(char *s)
{
  int		i;

  i = -1;
  while (s[++i])
    {
      if (!((s[i] >= '0') && (s[i] <= '9')))
	{
	  printf("is not number %c\n", s[i]);
	  return (0);
	}
    }
  return (1);
}
