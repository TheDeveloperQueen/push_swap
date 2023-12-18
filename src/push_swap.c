/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivasque <rivasque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:54:53 by rivasque          #+#    #+#             */
/*   Updated: 2023/12/14 11:19:41 by rivasque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Make sure min @ the top
void	min_top(t_stack **head_a, t_stack **head_b)
{
	t_stack	*smallest;

	smallest = find_smallest(*head_a);
	if (smallest->above_medium)
		while (*head_a != smallest)
			print_mov_rr(head_a, head_b, RA);
	else
		while (*head_a != smallest)
			print_mov_rrr(head_a, head_b, RRA);
}

bool	stack_sorted(t_stack *head)
{
	if (!head)
		return (NULL);
	while (head->next)
	{
		if (head->nbr > head->next->nbr)
			return (false);
		head = head->next;
	}
	return (true);
}

void	init_b(t_stack *head_a, t_stack *head_b)
{
	current_position(head_a);
	current_position(head_b);
	target_b(head_a, head_b);
}

t_stack	*sort_stack(t_stack **head_a, t_stack **head_b)
{
	if (!stack_sorted(*head_a))
	{
		if (stack_size(*head_a) == 2)
			sort_2(head_a);
		else if (stack_size(*head_a) == 3)
			sort_3(head_a);
		else if (stack_size(*head_a) == 4)
			sort_4(head_a, head_b);
		else if (stack_size(*head_a) == 5)
			sort_5(head_a, head_b);
		else if (stack_size(*head_a) > 5)
			sort_many(head_a, head_b);
	}
	return (*head_a);
}

int	main(int argc, char **argv)
{
	char	**array;
	t_stack	*a;
	t_stack	*b;

	array = NULL;
	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		array = ft_split(argv[1], ' ');
		if (!array[0] || !dig(array, a_l(array)) || !rep(array, a_l(array)))
			exit_error();
		a = create_stack_argv_one(array);
		free_array(array);
	}
	if (argc > 2)
	{
		if (!rep(argv + 1, argc - 1) || !dig(argv + 1, argc - 1) || !ntg(argv))
			exit_error();
		a = create_stack_argv(argv, argc);
	}
	sort_stack(&a, &b);
	return (free_stack(a), 0);
}
