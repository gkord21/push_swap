/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:02:37 by gkord             #+#    #+#             */
/*   Updated: 2022/02/26 19:36:46 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_create_elem(int num)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->num = num;
	new->next = new;
	new->prev = new;
	return (new);
}

void	ft_create_ab(t_ab *ab)
{
	ab->a = NULL;
	ab->b = NULL;
	ab->a_size = 0;
	ab->b_size = 0;
}

void	ft_add_elem_end(t_stack **a, t_stack *new)
{
	t_stack	*tmp;

	tmp = *a;
	if (!*a)
		*a = new;
	if (tmp)
	{
		new->next = tmp;
		new->prev = tmp->prev;
		tmp->prev->next = new;
		tmp->prev = new;
	}
}

int	ft_find_min(t_stack **first, int size)
{
	int		i;
	int		n;
	t_stack	*tmp;

	i = 0;
	tmp = *first;
	n = tmp->num;
	while (i < size)
	{
		if (n > tmp->num)
			n = tmp->num;
		tmp = tmp->next;
		i++;
	}
	return (n);
}

int	ft_find_max(t_stack	**first, int size)
{
	int		i;
	int		n;
	t_stack	*tmp;

	i = 0;
	tmp = *first;
	if (!*first)
		return (0);
	n = tmp->num;
	while (i < size)
	{
		if (n < tmp->num)
			n = tmp->num;
		tmp = tmp->next;
		i++;
	}
	return (n);
}
