/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sort_and_dub.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:32:45 by gkord             #+#    #+#             */
/*   Updated: 2022/03/06 15:24:49 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_sort(t_stack **first)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = *first;
	last = (*first)->prev;
	if (!(*first))
		return (-1);
	while (tmp != last)
	{
		if (tmp->num > tmp->next->num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_check_dub(t_stack **first, long int num, int size)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *first;
	while (i < size)
	{
		if (tmp->num == num)
			return (1);
		tmp = tmp->next;
		i++;
	}
	if (num > 2147483647 || num < -2147483648)
		return (1);
	return (0);
}
