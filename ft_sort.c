/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:42:34 by gkord             #+#    #+#             */
/*   Updated: 2022/03/05 20:33:45 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort3(t_ab *ab)
{
	int		min;
	int		max;
	t_stack	*tmp;

	tmp = ab->a;
	min = ft_find_min(&ab->a, ab->a_size);
	max = ft_find_max(&ab->a, ab->a_size);
	while (ft_check_sort(&ab->a))
	{
		if (tmp->num == max)
		{
			ft_rotate_process(ab, 'a');
			tmp = ab->a;
		}
		if (tmp->num < tmp->next->num && tmp->next->num == max)
		{
			ft_rev_rotate_process(ab, 'a');
			tmp = ab->a;
		}
		if (tmp->num > tmp->next->num && tmp->next->num == min)
		{
			ft_swap_process(ab, 'a');
			tmp = ab->a;
		}
	}
}

void	ft_sort5(t_ab *ab)
{
	int	min;
	int	max;

	min = ft_find_min(&ab->a, ab->a_size);
	max = ft_find_max(&ab->a, ab->a_size);
	while (ab->a_size != 3)
	{
		if (ab->a->num == max || ab->a->num == min)
			ft_rotate_process(ab, 'a');
		else
			ft_push_process(ab, 'b');
	}
	ft_sort3(ab);
	ft_rev_rotate_process(ab, 'a');
	if (ab->b->num < ab->b->next->num)
		ft_swap_process(ab, 'b');
	while (ab->b)
	{
		while ((ab->b->num > ab->a->num) || ab->a->prev->num > ab->b->num)
			ft_rev_rotate_process(ab, 'a');
		ft_push_process(ab, 'a');
	}
	while (ft_check_sort(&ab->a))
		ft_rev_rotate_process(ab, 'a');
}

void	ft_process_sort(t_ab *ab, int argc)
{
	if (argc == 3)
		ft_swap_process(ab, 'a');
	else if (argc == 4)
		ft_sort3(ab);
	else if (argc <= 6)
		ft_sort5(ab);
	else if (argc > 6)
		ft_big_sort(ab, argc);
}
