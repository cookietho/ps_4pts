/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 18:48:16 by minakim           #+#    #+#             */
/*   Updated: 2019/08/26 14:56:32 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_arrlen(int *arr)
{
	int	i;

	i = 0;
	while (arr[i] != '\0')
		i++;
	return (i);
}

int		*insertSort(t_stack *a, int n)
{
	int	i;
	int	*sortedArr;
	int		*arr;
	t_node	*tmp;
	
	arr = (int*)malloc(sizeof(int) * n + 1);

	i = 0;
	tmp = a->top;
	while (i++ < n)
	{
		arr[i] = tmp->value;
		tmp = tmp->next;
	}
	arr[i] = '\0';
	sortedArr = letsSort(arr, n);
	return (sortedArr);
}

void	b_to_a(t_stack *a, t_stack *b, int *arr)
{
	int	l;
	int	n;

	n = 0;
	l = ft_arrlen(arr) - 1;
	while (l >= 0)
	{
		if (arr[l] == 1) {
			pa(a, b);
		}
		else {
			n = arr[l];
			chunk_sorting(a, b, n);
		}
		l--;
	}
}
