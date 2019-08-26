/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                          :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 00:33:06 by minakim           #+#    #+#             */
/*   Updated: 2019/06/26 00:52:34 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack *stack)
{
	t_node	*a;
	t_node	*b;

	if (isEmpty(stack) == 0 && stack->top->next) {
		a = stack->top;
		b = stack->top->next;
		a->next = b->next;
		b->next = a;
		stack->top = b;
	}
	ft_printf("sa\n");
}

void	sb(t_stack *stack)
{
	t_node	*a;
	t_node	*b;

	if (isEmpty(stack) == 0 && stack->top->next) {
		a = stack->top;
		b = stack->top->next;
		a->next = b->next;
		b->next = a;
		stack->top = b;
	}
	ft_printf("sb\n");
}

void	ss(t_stack *stack1, t_stack *stack2)
{
	sa(stack1);
	sb(stack2);
	ft_printf("ss\n");
}

void	pa(t_stack *stack1, t_stack *stack2)
{
	int	tmp;

	if (isEmpty(stack2) == 1)
		return;
	tmp = pop(stack2);
	push(stack1, tmp);
	ft_printf("pa\n");
}

void	pb(t_stack *stack1, t_stack *stack2)
{
	int	tmp;

	if (isEmpty(stack1) == 1)
		return;
	tmp = pop(stack1);
	push(stack2, tmp);
	ft_printf("pb\n");
}
