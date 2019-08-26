/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:41:37 by minakim           #+#    #+#             */
/*   Updated: 2019/08/25 18:42:19 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_value(t_stack *a, t_struct *nbr)
{
	nbr->min = find_min(a);
	nbr->max = find_max(a);
	find_mid(a, nbr);
}

int		check_nbr(t_stack *a)
{
	int	count;
	t_node	*tmp;

	count = 0;
	tmp = a->top;
	while (tmp) {
		count++;
		tmp = tmp->next;
	}
	return (count);
}

char	*is_chunk_sorted2(int n, int *arr)
{
	int	i;
	int	a;
	int	b;
	char	*new;

	i = 0;
	a = 0;
	b = 0;

	while (arr[i++]) {
		if (arr[i] > arr[i + 1])
			a++;
		else if (arr[i] <= arr[i + 1])
			b++;
	}
	if (b == n)
		new = "B";
	else if (a == n)
		new = "A";
	else
		new = "false";
	return (new);
}

char	*is_chunk_sorted(t_stack *s, int n)
{
	int		i = 0;
	char	*answer;
	int		*arr;
	t_node	*tmp;	
	arr = (int*)malloc(sizeof(int) * n + 1);
	tmp = s->top;
	if (n == 2) {
		if (tmp->value < tmp->next->value)
			answer = "B";
		else
			answer = "A";
		return (answer);
	}
	while (i++ < n) {
		arr[i] = tmp->value;
	}
	arr[i] = '\0';
	answer = is_chunk_sorted2(n, arr);
	free(arr);
	return (answer);
}
