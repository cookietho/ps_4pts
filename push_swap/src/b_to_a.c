/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:44:39 by minakim           #+#    #+#             */
/*   Updated: 2019/08/25 20:50:25 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		count_arr(int n)
{
	int	count;
	int	tmp;

	tmp = n / 2;
	count = 1;
	while (tmp > 2) {
		tmp = tmp - tmp / 2;
		count++;
	}
	return (count);
}

int		mid_point(t_stack *s, int n)
{
	int	i;
	int	arr[n];
	int	*new_arr;
	t_node	*tmp;

	i = 0;
	tmp = s->top;
	while (i < n) {
		arr[i] = tmp->value;
		i++;
		tmp = tmp->next;
	}
	new_arr = letsSort(arr, n);
	i = n % 2 ? n / 2 :  n / 2 - 1;
	return (new_arr[i]);
}

void	push_to_a(t_stack *a, t_stack *b, int n)
{
	int	i;
	int	mid;
	int	count;
	t_node	*tmp;

	i = 0;
	count = 0;
	mid = mid_point(b, n);
	tmp = b->top;
	while (i < n) {
		if (tmp->value > mid)
			pa(a, b);
		else {
			rb(b);
			count++;
		}
		i++;
		tmp = b->top;
	}
	while (count-- > 0)
		rrb(b);
}

void	chunk_sorting(t_stack *a, t_stack *b, int n)
{
	int	nbr_a;
	int	arr[count_arr(n)];
	int	i;

	i = 1;
	if (n >= 1 && n <= 2)
		chunk_sorting2(a, b, n);
	else {
		push_to_a(a, b, n);
		nbr_a = n / 2;
		arr[0] = n - nbr_a;
		while (nbr_a > 2) {
			arr[i] = a_to_b(a, b, nbr_a);
			nbr_a = nbr_a % 2 ? nbr_a / 2 + 1 : nbr_a / 2;
			i++;
		}
		if (ft_strcmp(is_chunk_sorted(a, 2), "A") == 0)
			sa(a);
		i = count_arr(n) - 1;
		while (i >= 0)
			chunk_sorting(a, b, arr[i--]);
	}
}
