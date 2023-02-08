/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:03:49 by gkord             #+#    #+#             */
/*   Updated: 2022/02/26 19:36:23 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **to, t_stack **from)
{
	t_stack	*tmp_from;

	tmp_from = NULL;
	if ((*from) != (*from)->next)
	{
		tmp_from = (*from)->next;
		tmp_from->prev = (*from)->prev;
		(*from)->prev->next = tmp_from;
	}
	if (!(*to))
	{
		(*from)->next = *from;
		(*from)->prev = *from;
	}
	else
	{
		(*from)->next = *to;
		(*to)->prev->next = *from;
		(*from)->prev = (*to)->prev;
		(*to)->prev = *from;
	}
	*to = *from;
	*from = tmp_from;
}

void	ft_push_process(t_ab *ab, char c)
{
	if (c == 'a' && ab->b)
	{
		ft_push(&ab->a, &ab->b);
		ab->a_size++;
		ab->b_size--;
		write(1, "pa\n", 3);
	}
	if (c == 'b' && ab->a)
	{
		ft_push(&ab->b, &ab->a);
		ab->a_size--;
		ab->b_size++;
		write(1, "pb\n", 3);
	}
}
