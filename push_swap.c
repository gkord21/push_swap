/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:35:21 by gkord             #+#    #+#             */
/*   Updated: 2022/03/11 16:31:16 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			i;
	t_ab		ab;

	i = 1;
	ft_create_ab(&ab);
	if (argc > 1)
	{
		ft_get_num(argc, argv, i, &ab);
		if (ft_check_sort(&ab.a))
			ft_process_sort(&ab, (ab.a_size + 1));
	}
	return (0);
}
