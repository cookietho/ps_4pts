/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 00:33:06 by minakim           #+#    #+#             */
/*   Updated: 2019/08/26 15:00:09 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		mid_point_a(t_stack *a, int n)
{
	int	i;
	int	arr[n];
	int	*new_arr;
	t_node	*tmp;

	i = 0;
	tmp = a->top;
	while (i < n) {
		arr[i] = tmp->value;
		i++;
		tmp = tmp->next;
	}
	new_arr = letsSort(arr, n);
	return (new_arr[n / 2]);
}

int		a_to_b(t_stack *a, t_stack *b, int n)
{
	int	i;
	int	mid;
	int	count;
	t_node	*tmp;

	i = 0;
	count = 0;
	mid = mid_point_a(a, n);
	tmp = a->top;
	while (i++ < n) {
		if (tmp->value < mid)
			pb(a, b);
		else {
			ra(a);
			count++;
		}
		tmp = a->top;
	}
	while (count-- > 0)
		rra(a);
	return (n / 2);
}

void	chunk_sorting2(t_stack *a, t_stack *b, int n)
{
	if (n == 1)
		pa(a, b);
	else if (n == 2) {
		if (ft_strcmp(is_chunk_sorted(b, n), "B") == 0)
			sb(b);
		while (n-- > 0)
			pa(a, b);
	}
}
