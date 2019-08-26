/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:10:25 by minakim           #+#    #+#             */
/*   Updated: 2019/08/22 13:46:48 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sorting_0(t_stack *a)
{
	if (a->top->value > a->top->next->value)
		sa(a);
}

void	sorting_1(t_stack *a)
{
	t_struct	*nbr;

	nbr = init_nbr();
	check_value(a, nbr);
	if (a->top->value == nbr->min && a->top->next->value == nbr->max)
	{
		sa(a);
		ra(a);
	}
	else if (a->top->value == nbr->mid)
	{
		if (a->top->next->value == nbr->min)
			sa(a);
		else
			rra(a);
	}
	else if  (a->top->value == nbr->max)
	{
		if (a->top->next->value == nbr->mid)
		{
			sa(a);
			rra(a);
		}
		else
			ra(a);
	}
	free(nbr);
}

void	sorting_2(t_stack *a, t_stack *b)
{
	int	*arr;
	int	count;
	t_pivot	*new;
	int	bot;
	int	*chunk;
	int	i;

	bot = 0;
	i = 0;
	new = init_pivot();
	chunk = create_arr(check_nbr(a));
	while (!isEmpty(a)) {
		count = 0;
		arr = insertionSort(a);
		find_pivot(a, arr, new);
		while (count < new->left_nbr) {
			bot = find_bot(a);
			if (a->top->value < new->i_value) {
				pb(a, b);
				count++;
			}
			else if (bot < new->i_value) {
				rra(a);
				pb(a, b);
				count++;
			}
			else
				ra(a);
		}
		chunk[i] = count;
		i++;
		if (check_nbr(a) == 1) {
			pb(a, b);
			chunk[i] = 1;
			chunk[i + 1] = '\0';
		}
	}
	b_to_a(a, b, chunk);
	free(arr);
	free(new);
}

void	sorting_3(t_stack*a, t_stack *b)
{
	pb(a, b);
	pb(a, b);
	sorting_1(a);
	while (!isEmpty(b))
	{
		if (b->top->value <= a->top->value)
			pa(a, b);
		else if (b->top->value >= find_max(a))
		{
			pa(a, b);
			ra(a);
		}
		else if (b->top->value < find_max(a) && b->top->value >= a->top->next->value)
		{
			if (check_nbr(a) == 3) {
				pa(a, b);
				rra(a);
				sa(a);
				ra(a);
				ra(a);
			}
			else {
				if (b->top->value >= a->top->next->next->value) {
					pa(a, b);
					sa(a);
					ra(a);
					ra(a);
				}
				else {
					rra(a);
					rra(a);
					pa(a, b);
					ra(a);
					ra(a);
					ra(a);
				}
			}
		}
		else if (b->top->value > a->top->value && b->top->value < a->top->next->value) {
			pa(a, b);
			sa(a);
		}
	}
}
