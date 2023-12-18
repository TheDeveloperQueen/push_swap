/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivasque <rivasque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:43:10 by ritavasques       #+#    #+#             */
/*   Updated: 2023/12/14 11:13:55 by rivasque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Iterate on b to find target for a
// Check if b is smaller than a && bigger than the closest smaller
void	target_a(t_stack *head_a, t_stack *head_b)
{
	t_stack	*aux_b;
	t_stack	*target;
	long	best_index;

	while (head_a)
	{
		best_index = LONG_MIN;
		aux_b = head_b;
		while (aux_b)
		{
			if (aux_b->nbr < head_a->nbr && aux_b->nbr > best_index)
			{
				best_index = aux_b->nbr;
				target = aux_b;
			}
			aux_b = aux_b->next;
		}
		if (best_index == LONG_MIN)
			head_a->target = find_max(head_b);
		else
			head_a->target = target;
		head_a = head_a->next;
	}
}

// Iterate on a to find target for b
void	target_b(t_stack *head_a, t_stack *head_b)
{
	t_stack	*aux_a;
	t_stack	*target;
	long	best_index;

	while (head_b)
	{
		best_index = LONG_MAX;
		aux_a = head_a;
		while (aux_a)
		{
			if (aux_a->nbr > head_b->nbr && aux_a->nbr < best_index)
			{
				best_index = aux_a->nbr;
				target = aux_a;
			}
			aux_a = aux_a->next;
		}
		if (best_index == LONG_MAX)
			head_b->target = find_smallest(head_a);
		else
			head_b->target = target;
		head_b = head_b->next;
	}
}

// Sum of rotations for a to be on top + target to be on top
void	cost_to_move(t_stack *head_a, t_stack *head_b)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(head_a);
	size_b = stack_size(head_b);
	while (head_a)
	{
		head_a->cost = head_a->position;
		if (!(head_a->above_medium))
			head_a->cost = size_a - (head_a->position);
		if (head_a->target->above_medium)
			head_a->cost += head_a->target->position;
		else
			head_a->cost += size_b - (head_a->target->position);
		head_a = head_a->next;
	}
}

//Use the cost to flag cheapest node
void	find_cheap(t_stack *head)
{
	long	cheapest_move;
	t_stack	*cheapest;

	if (!head)
		return ;
	cheapest_move = LONG_MAX;
	while (head)
	{
		if (head->cost < cheapest_move)
		{
			cheapest_move = head->cost;
			cheapest = head;
		}
		head = head->next;
	}
	cheapest->cheap = true;
}

// Serach for cheapest set by find_cheap
t_stack	*get_cheap(t_stack *head)
{
	if (!head)
		return (NULL);
	while (head)
	{
		if (head->cheap)
			return (head);
		head = head->next;
	}
	return (NULL);
}
