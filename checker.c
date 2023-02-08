/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:31:09 by gkord             #+#    #+#             */
/*   Updated: 2022/03/11 16:55:24 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_checker_process3(t_ab *ab, char *line)
{
	if (!ft_strncmp("ra\n", line, 3))
		ft_rotate(&ab->a);
	else if (!ft_strncmp("rb\n", line, 3))
		ft_rotate(&ab->b);
	else
		ft_error_exit();
}

void	ft_checker_process2(t_ab *ab, char *line)
{
	if (!ft_strncmp("pa\n", line, 3))
	{
		ft_push(&ab->a, &ab->b);
		ab->a_size++;
		ab->b_size--;
	}
	else if (!ft_strncmp("pb\n", line, 3))
	{
		ft_push(&ab->b, &ab->a);
		ab->a_size--;
		ab->b_size++;
	}
	else if (!ft_strncmp("rra\n", line, 4))
		ft_rev_rotate(&ab->a, ab->a_size);
	else if (!ft_strncmp("rrb\n", line, 4))
		ft_rev_rotate(&ab->b, ab->b_size);
	else if (!ft_strncmp("rrr\n", line, 4))
	{
		ft_rev_rotate(&ab->a, ab->a_size);
		ft_rev_rotate(&ab->b, ab->b_size);
	}
	else
		ft_checker_process3(ab, line);
}

void	ft_checker_process(t_ab *ab)
{
	char	*line;

	line = NULL;
	line = get_next_line(0);
	while (line)
	{
		if (!ft_strncmp("sa\n", line, 3))
			ft_swap(&ab->a);
		else if (!ft_strncmp("sb\n", line, 3))
			ft_swap(&ab->b);
		else if (!ft_strncmp("ss\n", line, 3))
		{
			ft_swap(&ab->a);
			ft_swap(&ab->b);
		}
		else if (!ft_strncmp("rr\n", line, 3))
		{
			ft_rotate(&ab->a);
			ft_rotate(&ab->b);
		}
		else
			ft_checker_process2(ab, line);
		free(line);
		line = get_next_line(0);
	}
}

void	ft_solution(t_ab *ab)
{
	if (!ft_check_sort(&ab->a) && ab->a_size && !(ab->b_size))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

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
			ft_checker_process(&ab);
		ft_solution(&ab);
	}
	return (0);
}
