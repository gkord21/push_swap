/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:29:36 by gkord             #+#    #+#             */
/*   Updated: 2022/03/11 16:05:44 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	ft_skip(const char *str, int *i)
{
	unsigned int	j;

	j = 0;
	while (str[j] == ' ' || (str[j] >= 9 && str[j] <= 13))
		j++;
	if (str[j] == '-')
	{
		*i = -(*i);
		++j;
		if (!ft_isdigit(str[j]))
		{
			write(2, "Error\n", 6);
			exit(-1);
		}
	}
	if (str[j] == '+')
	{
		++j;
		if (!ft_isdigit(str[j]))
		{
			write(2, "Error\n", 6);
			exit(-1);
		}
	}
	return (j);
}

int	ft_atoi(const char *str)
{
	int				i;
	unsigned int	j;
	unsigned int	tmp;
	long int		ans;

	i = 1;
	ans = 0;
	j = ft_skip(str, &i);
	tmp = j;
	while (str[tmp])
	{
		if (!ft_isdigit(str[tmp]))
			ft_error_exit();
		tmp++;
	}
	while (str[j] >= '0' && str[j] <= '9')
	{
		ans = ans * 10 + str[j] - 48;
		j++;
		if (ans > 2147483647 || ans < -2147483648)
			ft_error_exit();
	}
	return (ans * i);
}
