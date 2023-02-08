/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:25:25 by gkord             #+#    #+#             */
/*   Updated: 2022/03/06 15:20:37 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_arr(int *arr, int argc)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*ft_create_arr(t_ab *ab, int argc)
{
	int		i;
	int		*arr;
	t_stack	*tmp;

	i = 0;
	tmp = ab->a;
	arr = (int *)malloc(sizeof(int) * (argc - 1));
	if (!arr)
		return (NULL);
	while (i < argc - 1)
	{
		arr[i] = tmp->num;
		tmp = tmp->next;
		i++;
	}
	ft_sort_arr(arr, argc);
	return (arr);
}
