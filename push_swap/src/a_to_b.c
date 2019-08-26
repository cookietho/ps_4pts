#include "../includes/push_swap.h"

int		mid_point_a(t_stack *a, int n)
{
	int	i;
	int	arr[n];
	int	*new_arr;
	t_node	*tmp;

	i = 0;
	tmp = a->top;
	while (i < n)
	{
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
	while (i < n)
	{
		if (tmp->value < mid)
			pb(a, b);
		else {
			ra(a);
			count++;
		}
		i++;
		tmp = a->top;
	}
	while (count-- > 0)
		rra(a);
	return (n / 2);
}
