/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:37:49 by gkord             #+#    #+#             */
/*   Updated: 2022/02/26 19:36:00 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_print_stack(t_ab *ab, char c)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	if (c == 'a')
	{
		tmp = ab->a;
		printf ("a = ");
		while (i < ab->a_size)
		{
			printf ("%d ", tmp->num);
			tmp = tmp->next;
			i++;
		}
	}
	if (c == 'b')
	{
		tmp = ab->b;
		printf ("b = ");
		while (i < ab->b_size)
		{
			printf ("%d ", tmp->num);
			tmp = tmp->next;
			i++;
		}
	}
	printf("\n");
}
