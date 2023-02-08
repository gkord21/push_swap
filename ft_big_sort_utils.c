/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 22:17:43 by gkord             #+#    #+#             */
/*   Updated: 2022/02/26 19:21:14 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_find_min_score(t_ab *ab, int *position)
{
	int		i;
	t_stack	*tmp;
	t_stack	*min_score_elem;

	i = 1;
	*position = 0;
	tmp = ab->b->next;
	min_score_elem = ab->b;
	while (i < ab->b_size)
	{
		if (tmp->score < min_score_elem->score && tmp)
		{
			*position = i;
			min_score_elem = tmp;
		}
		i++;
		tmp = tmp->next;
	}
	return (min_score_elem);
}

void	ft_rot_ab(t_ab *ab, int *rot_a_score, int *rot_b_score)
{
	while (*rot_b_score > 0 && *rot_a_score > 0)
	{
		ft_rotate_process(ab, 'r');
		--*rot_b_score;
		--*rot_a_score;
	}
	while (*rot_a_score > 0)
	{
		ft_rotate_process(ab, 'a');
		--*rot_a_score;
	}
	while (*rot_b_score > 0)
	{
		ft_rotate_process(ab, 'b');
		--*rot_b_score;
	}
}

void	ft_rev_rot_ab(t_ab *ab, int	*rot_a_score, int *rot_b_score)
{
	while (*rot_b_score < 0 && *rot_a_score < 0)
	{
		ft_rev_rotate_process(ab, 'r');
		++*rot_b_score;
		++*rot_a_score;
	}
	while (*rot_a_score < 0)
	{
		ft_rev_rotate_process(ab, 'a');
		++*rot_a_score;
	}
	while (*rot_b_score < 0)
	{
		ft_rev_rotate_process(ab, 'b');
		++*rot_b_score;
	}
}

void	ft_rot_and_push_ab(t_ab *ab, t_stack *min_score, int position)
{
	int	rot_a_score;
	int	rot_b_score;

	rot_a_score = ft_count_of_rot_a(ab, min_score->num);
	if (position < ab->b_size - position)
		rot_b_score = position;
	else
		rot_b_score = position - ab->b_size;
	if (rot_b_score > 0 || rot_a_score > 0)
		ft_rot_ab(ab, &rot_a_score, &rot_b_score);
	if (rot_b_score < 0 || rot_a_score < 0)
		ft_rev_rot_ab(ab, &rot_a_score, &rot_b_score);
	ft_push_process(ab, 'a');
}

void	ft_final_rot(t_ab *ab)
{
	t_stack	*tmp;
	int		i;
	int		max_a;

	i = 0;
	tmp = ab->a;
	max_a = ft_find_max(&ab->a, ab->a_size);
	while (i < ab->a_size && tmp->num < max_a)
	{
		tmp = tmp->next;
		i++;
	}
	while (ft_check_sort(&ab->a))
	{
		if (i < ab->a_size - i)
			ft_rotate_process(ab, 'a');
		else
			ft_rev_rotate_process(ab, 'a');
	}
}
