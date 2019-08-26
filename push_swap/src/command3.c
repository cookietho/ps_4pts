#include "../includes/push_swap.h"

void rra(t_stack *stack)
{
	t_node	*a;
	t_node	*b;
	t_node	*c;

	if (isEmpty(stack) == 1 || !stack->top->next)
		return;
	a = stack->top;
	b = stack->top;
	c = stack->top;
	while (b->next->next)
		b = b->next;
	c = b->next;
	c->next = a;
	b->next = NULL;
	stack->top = c;
	ft_printf("rra\n");
}

void rrb(t_stack *stack)
{
	t_node	*a;
	t_node	*b;
	t_node	*c;

	if (isEmpty(stack) == 1 || !stack->top->next)
		return;
	a = stack->top;
	b = stack->top;
	c = stack->top;
	while (b->next->next)
		b = b->next;
	c = b->next;
	c->next = a;
	b->next = NULL;
	stack->top = c;
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}
