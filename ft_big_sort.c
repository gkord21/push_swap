/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:57:13 by gkord             #+#    #+#             */
/*   Updated: 2022/02/26 19:35:11 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_b(t_ab *ab, int min, int mid, int max)
{
	while (ab->a_size > 2)
	{
		if (ab->a->num > mid && ab->a->num != min && ab->a->num != max)
		{
			ft_push_process(ab, 'b');
			ft_rotate_process(ab, 'b');
		}
		else if (ab->a->num <= mid && ab->a->num != min && ab->a->num != max)
			ft_push_process(ab, 'b');
		else
			ft_rotate_process(ab, 'a');
	}
	if (ab->a->num == min)
		ft_rotate_process(ab, 'a');
}

int	ft_count_of_rot_a(t_ab *ab, int num)
{
	int		res;
	t_stack	*tmp;

	res = 0;
	tmp = ab->a;
	while (num > tmp->num || tmp->prev->num > num)
	{
		tmp = tmp->next;
		res++;
	}
	if (res < ab->a_size - res)
		return (res);
	else
		return (res - ab->a_size);
}

void	ft_score_of_rot(t_ab *ab, t_stack *b, int i)
{
	int	rot_a_score;
	int	rot_b_score;

	rot_a_score = ft_count_of_rot_a(ab, b->num);
	if (i < ab->b_size - i)
		rot_b_score = i;
	else
		rot_b_score = i - ab->b_size;
	if ((rot_a_score > 0 && rot_b_score > 0)
		|| (rot_a_score < 0 && rot_b_score < 0))
	{
		if (ft_mod(rot_a_score) > ft_mod(rot_b_score))
			b->score = ft_mod(rot_a_score);
		else
			b->score = ft_mod(rot_b_score);
	}
	else
		b->score = ft_mod(rot_b_score) + ft_mod(rot_a_score);
}

void	ft_big_sort_process(t_ab *ab)
{
	t_stack	*tmp;
	t_stack	*min_score;
	int		i;
	int		position;

	i = 0;
	tmp = ab->b;
	while (i < ab->b_size)
	{
		ft_score_of_rot(ab, tmp, i);
		tmp = tmp->next;
		i++;
	}
	min_score = ft_find_min_score(ab, &position);
	ft_rot_and_push_ab(ab, min_score, position);
}

void	ft_big_sort(t_ab *ab, int argc)
{
	int	*sort_arr;
	int	mid;
	int	min;
	int	max;

	sort_arr = ft_create_arr(ab, argc);
	mid = sort_arr[(argc - 1) / 2];
	min = sort_arr[0];
	max = sort_arr[argc - 2];
	ft_push_b(ab, min, mid, max);
	while (ab->b != NULL)
		ft_big_sort_process(ab);
	ft_final_rot(ab);
	free(sort_arr);
}
