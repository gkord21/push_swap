/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:27:39 by gkord             #+#    #+#             */
/*   Updated: 2022/03/11 14:54:51 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "get_next_line/get_next_line.h"

typedef struct s_stack
{
	int				num;
	int				score;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_ab
{
	struct s_stack	*a;
	struct s_stack	*b;
	int				a_size;
	int				b_size;
}	t_ab;

int				ft_atoi(const char *str);
unsigned int	ft_skip(const char *str, int *i);
void			ft_error_exit(void);
int				ft_isdigit(int i);
t_stack			*ft_create_elem(int num);
void			ft_swap(t_stack **first);
void			ft_swap_process(t_ab *ab, char c);
void			ft_rotate(t_stack **first);
void			ft_rotate_process(t_ab *ab, char c);
void			ft_rev_rotate(t_stack **first, int stack_size);
void			ft_rev_rotate_process(t_ab *ab, char c);
void			ft_push(t_stack **to, t_stack **from);
void			ft_push_process(t_ab *ab, char c);
void			ft_process_sort(t_ab *ab, int argc);
void			ft_create_ab(t_ab *ab);
void			ft_add_elem_end(t_stack **a, t_stack *new);
int				ft_check_dub(t_stack **first, long int num, int size);
int				ft_check_sort(t_stack **first);
int				ft_find_min(t_stack **first, int size);
int				ft_find_max(t_stack	**first, int size);
void			ft_push_b(t_ab *ab, int min, int mid, int max);
int				ft_count_of_rot_a(t_ab *ab, int num);
void			ft_score_of_rot(t_ab *ab, t_stack *b, int i);
void			ft_big_sort_process(t_ab *ab);
void			ft_big_sort(t_ab *ab, int argc);
t_stack			*ft_find_min_score(t_ab *ab, int *position);
void			ft_rot_ab(t_ab *ab, int *rot_a_score, int *rot_b_score);
void			ft_rev_rot_ab(t_ab *ab, int	*rot_a_score, int *rot_b_score);
void			ft_rot_and_push_ab(t_ab *ab, t_stack *min_score, int position);
void			ft_final_rot(t_ab *ab);
void			ft_sort_arr(int *arr, int argc);
int				*ft_create_arr(t_ab *ab, int argc);
int				ft_mod(int num);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			**ft_split(char const *s, char c);
int				ft_strlen(const char *str);
void			ft_get_num(int argc, char **argv, int i, t_ab *ab);

#endif