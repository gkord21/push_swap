/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:32:30 by gkord             #+#    #+#             */
/*   Updated: 2022/03/11 16:34:19 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_array(char **tmp)
{
	size_t	i;

	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

void	ft_get_num(int argc, char **argv, int i, t_ab *ab)
{
	char		**tmp;
	int			j;
	long int	num;
	t_stack		*tmp_elem;

	while (argv[i])
	{
		tmp = ft_split(argv[i], ' ');
		if (tmp[0] == '\0')
			ft_error_exit();
		j = 0;
		while (tmp[j])
		{
			num = ft_atoi(tmp[j]);
			tmp_elem = ft_create_elem(num);
			if (!tmp_elem || ft_check_dub(&ab->a, num, ab->a_size))
				ft_error_exit();
			ft_add_elem_end(&ab->a, tmp_elem);
			ab->a_size++;
			j++;
		}
		i++;
		ft_free_array(tmp);
	}
}
