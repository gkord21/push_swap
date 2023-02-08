/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:30:02 by gkord             #+#    #+#             */
/*   Updated: 2022/02/26 19:36:28 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate(t_stack **first, int stack_size)
{
	int		j;
	t_stack	*tmp;

	j = 0;
	tmp = *first;
	while (j < stack_size - 1)
	{
		tmp = tmp->next;
		j++;
	}
	(*first) = tmp;
}

void	ft_rev_rotate_process(t_ab *ab, char c)
{
	if (c == 'a' && ab->a)
	{
		ft_rev_rotate(&ab->a, ab->a_size);
		write(1, "rra\n", 4);
	}
	if (c == 'b' && ab->b)
	{
		ft_rev_rotate(&ab->b, ab->b_size);
		write(1, "rrb\n", 4);
	}
	if (c == 'r' && ab->a && ab->b)
	{
		ft_rev_rotate(&ab->a, ab->a_size);
		ft_rev_rotate(&ab->b, ab->b_size);
		write(1, "rrr\n", 4);
	}
}
