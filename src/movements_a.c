/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivasque <rivasque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:59:59 by rivasque          #+#    #+#             */
/*   Updated: 2023/12/14 11:15:24 by rivasque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// SWAP A 1ST 2 ELEMNTS
void	sa(t_stack *head)
{
	if (stack_size(head) > 1)
	{
		ft_swap(&(head->nbr), &(head->next->nbr));
		ft_printf("sa\n");
	}
}

// 1ST ELEMENT B TO TOP OF A
void	pa(t_stack **head_a, t_stack **head_b)
{
	t_stack	*new;

	if (stack_size(*head_b) > 0)
	{
		new = (t_stack *) malloc(sizeof(t_stack));
		if (!new)
			return ;
		new->nbr = (*head_b)->nbr;
		new->next = *head_a;
		*head_a = new;
		delete_1st(head_b);
		ft_printf("pa\n");
	}
}

// SHIFT UP ALL ELEMENTS BY 1
void	ra(t_stack **head)
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
void	rra(t_stack **head)
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

void	move_b_to_a(t_stack **head_a, t_stack **head_b)
{
	check_push_a(head_a, head_b, (*head_b)->target);
	pa(head_a, head_b);
}
