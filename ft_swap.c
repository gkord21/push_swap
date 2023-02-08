/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:53:22 by gkord             #+#    #+#             */
/*   Updated: 2022/02/26 19:36:58 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **first)
{
	int		tmp;

	tmp = (*first)->num;
	(*first)->num = (*first)->next->num;
	(*first)->next->num = tmp;
}

void	ft_swap_process(t_ab *ab, char c)
{
	if (c == 'a' && ab->a && ab->a->next)
	{
		ft_swap(&ab->a);
		write(1, "sa\n", 3);
	}
	if (c == 'b' && ab->b && ab->b->next)
	{
		ft_swap(&ab->b);
		write(1, "sb\n", 3);
	}
	if (c == 's' && ab->a && ab->a->next && ab->b && ab->b->next)
	{
		ft_swap(&ab->a);
		ft_swap(&ab->b);
		write(1, "ss\n", 3);
	}
}
