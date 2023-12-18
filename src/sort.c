/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivasque <rivasque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:26:51 by rivasque          #+#    #+#             */
/*   Updated: 2023/12/13 14:56:20 by rivasque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"

void	sort_2(t_stack **head)
{
	t_stack	*temp;

	temp = *head;
	if (temp->nbr > temp->next->nbr)
		sa(temp);
}

void	sort_3(t_stack **head)
{
	if ((*head)->nbr > (*head)->next->nbr && \
	(*head)->nbr > (*head)->next->next->nbr)
	{
		print_mov_rr(head, NULL, RA);
	}
	else if ((*head)->nbr < (*head)->next->nbr && \
	(*head)->next->nbr > (*head)->next->next->nbr)
		print_mov_rrr(head, NULL, RRA);
	sort_2(head);
}

void	sort_4(t_stack **head_a, t_stack **head_b)
{
	int	min_pos;

	min_pos = find_min_pos(head_a);
	if (min_pos <= (stack_size(*head_a) / 2))
	{
		while (min_pos > 0)
		{
			print_mov_rr(head_a, NULL, RA);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < stack_size(*head_a))
		{
			print_mov_rrr(head_a, NULL, RRA);
			min_pos++;
		}
	}
	pb(head_a, head_b);
	sort_3(head_a);
	pa(head_a, head_b);
}

void	sort_5(t_stack **head_a, t_stack **head_b)
{
	int	min_pos;

	min_pos = find_min_pos(head_a);
	if (min_pos <= (stack_size(*head_a) / 2))
	{
		while (min_pos > 0)
		{
			print_mov_rr(head_a, NULL, RA);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < stack_size(*head_a))
		{
			print_mov_rrr(head_a, NULL, RRA);
			min_pos++;
		}
	}
	pb(head_a, head_b);
	sort_4(head_a, head_b);
	pa(head_a, head_b);
}

void	sort_many(t_stack **head_a, t_stack **head_b)
{
	int	size;

	pb(head_a, head_b);
	pb(head_a, head_b);
	size = stack_size(*head_a);
	while (size-- > 3 && !stack_sorted(*head_a))
	{
		init_a(*head_a, *head_b);
		move_a_to_b(head_a, head_b);
	}
	sort_3(head_a);
	while (*head_b)
	{
		init_b(*head_a, *head_b);
		move_b_to_a(head_a, head_b);
	}
	current_position(*head_a);
	min_top(head_a, head_b);
}
