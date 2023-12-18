/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivasque <rivasque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:14:25 by rivasque          #+#    #+#             */
/*   Updated: 2023/12/14 11:15:37 by rivasque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// SWAP A 1ST 2 ELEMNTS
void	sb(t_stack *head)
{
	if (stack_size(head) > 1)
	{
		ft_swap(&(head->nbr), &(head->next->nbr));
		ft_printf("sb\n");
	}
}

// 1ST ELEMENT A TO TOP OF B
void	pb(t_stack **head_a, t_stack **head_b)
{
	t_stack	*new;

	if (stack_size(*head_a) > 0)
	{
		new = (t_stack *) malloc(sizeof(t_stack));
		if (!new)
			return ;
		new->nbr = (*head_a)->nbr;
		new->next = *head_b;
		*head_b = new;
		delete_1st(head_a);
		ft_printf("pb\n");
	}
}

// SHIFT UP ALL ELEMENTS BY 1
void	rb(t_stack **head)
{
	t_stack	*temp;

	temp = *head;
	if (!temp)
		return ;
	while (temp->next)
		temp = temp->next;
	temp->next = *head;
	*head = (*head)->next;
	temp->next->next = NULL;
}

//SHIFT DOWN ALL ELEMENTS BY 1
void	rrb(t_stack **head)
{
	t_stack	*second_last;
	t_stack	*last;

	second_last = NULL;
	last = *head;
	if (!last)
		return ;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *head;
	*head = last;
}

void	move_a_to_b(t_stack **head_a, t_stack **head_b)
{
	t_stack	*cheapest;

	cheapest = get_cheap(*head_a);
	if (cheapest->above_medium && cheapest->target->above_medium)
		move_both_rr(head_a, head_b, cheapest);
	else if (!(cheapest->above_medium) && !(cheapest->target->above_medium))
		move_both_rrr(head_a, head_b, cheapest);
	check_push_a(head_a, head_b, cheapest);
	check_push_b(head_a, head_b, cheapest->target);
	pb(head_a, head_b);
}
