/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:22:47 by gkord             #+#    #+#             */
/*   Updated: 2022/02/26 19:36:34 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **first)
{
	t_stack	*second;

	second = (*first)->next;
	(*first) = second;
}

void	ft_rotate_process(t_ab *ab, char c)
{
	if (c == 'a' && ab->a)
	{
		ft_rotate(&ab->a);
		write(1, "ra\n", 3);
	}
	if (c == 'b' && ab->b)
	{
		ft_rotate(&ab->b);
		write(1, "rb\n", 3);
	}
	if (c == 'r' && ab->a && ab->b)
	{
		ft_rotate(&ab->a);
		ft_rotate(&ab->b);
		write(1, "rr\n", 3);
	}
}
