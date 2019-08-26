/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 23:16:16 by minakim           #+#    #+#             */
/*   Updated: 2019/08/25 19:23:10 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(struct s_stack *stack)
{
	struct s_node	*tmp = stack->top;

	while (tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

int	isInt(char *str)
{
	int	i; 

	i = 0;
	while(str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	struct s_stack	*a;
	struct s_stack	*b;
	char	*str;

	a = initstack();
	b = initstack();
	if (ac >= 2)
	{
		int	i;

		i = ac - 1;
		while (av[i] && i != 0)
		{
			if (isInt(av[i]) == 1) {
				ft_printf("ERROR\n");
				exit(0);
			}
			push(a, ft_atoi(av[i]));
			i--;
		}
		while (get_next_line(0, &str) == 1)
		{
			if (!ft_strcmp("sa", str))
				sa(a);
			else if (!ft_strcmp("sb", str))
				sb(b);
			else if (!ft_strcmp("ss", str))
				ss(a, b);
			else if (!ft_strcmp("pa", str))
				pa(a, b);
			else if (!ft_strcmp("pb", str))
				pb(a, b);
			else if (!ft_strcmp("ra", str))
				ra(a);
			else if (!ft_strcmp("rb", str))
				rb(b);
			else if (!ft_strcmp("rr", str))
				rr(a, b);
			else if (!ft_strcmp("rra", str))
				rra(a);			
			else if (!ft_strcmp("rrb", str))
				rrb(b);
			else if (!ft_strcmp("rrr", str))
				rrr(a, b);
			else {
				ft_printf("ERROR\n");
				exit (0);
			}
//			ft_printf("A stack\n");
//			print_stack(a);
//			ft_printf("B stack\n");
//			print_stack(b);
		}
		sort(a);
	}
	return (0);
}
