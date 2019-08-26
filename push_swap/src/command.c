/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 00:33:06 by minakim           #+#    #+#             */
/*   Updated: 2019/06/26 00:52:34 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack *stack)
{
	t_node	*tmp1;
	t_node	*tmp2;

	if (isEmpty(stack) == 1 || !stack->top->next)
		return;
	tmp1 = stack->top;
	tmp2 = stack->top;
	stack->top = stack->top->next;
	while (tmp1->next) {
		tmp1 = tmp1->next;
	}
	tmp1->next = tmp2;
	tmp2->next = NULL;
	ft_printf("ra\n");
}

void	rb(t_stack *stack)
{
	t_node	*tmp1;
	t_node	*tmp2;

	if (isEmpty(stack) == 1 || !stack->top->next)
		return;
	tmp1 = stack->top;
	tmp2 = stack->top;
	stack->top = stack->top->next;
	while (tmp1->next)
		tmp1 = tmp1->next;
	tmp1->next = tmp2;
	tmp2->next = NULL;
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	ft_printf("rr\n");
}
