/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:09:04 by rivasque          #+#    #+#             */
/*   Updated: 2023/12/11 17:40:17 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *head_a, t_stack *head_b)
{
	if (stack_size(head_a) > 1 && stack_size(head_b) > 1)
	{
		ft_swap(&(head_a->nbr), &(head_a->next->nbr));
		ft_swap(&(head_b->nbr), &(head_b->next->nbr));
		ft_printf("ss\n");
	}
}

void	print_mov_rr(t_stack **head_a, t_stack **head_b, int move)
{
	if (move == RA)
	{
		ra(head_a);
		ft_printf("ra\n");
	}
	if (move == RB)
	{
		rb(head_b);
		ft_printf("rb\n");
	}
	if (move == RR)
	{
		ra(head_a);
		rb(head_b);
		ft_printf("rr\n");
	}
}

void	print_mov_rrr(t_stack **head_a, t_stack **head_b, int move)
{
	if (move == RRA)
	{
		rra(head_a);
		ft_printf("rra\n");
	}
	if (move == RRB)
	{
		rrb(head_b);
		ft_printf("rrb\n");
	}
	if (move == RRR)
	{
		rra(head_a);
		rrb(head_b);
		ft_printf("rrr\n");
	}
}

void	move_both_rr(t_stack **head_a, t_stack **head_b, t_stack *cheapest)
{
	while (*head_b != cheapest->target && *head_a != cheapest)
		print_mov_rr(head_a, head_b, RR);
	current_position(*head_a);
	current_position(*head_b);
}

void	move_both_rrr(t_stack **head_a, t_stack **head_b, t_stack *cheapest)
{
	while (*head_b != cheapest->target && *head_a != cheapest)
		print_mov_rrr(head_a, head_b, RRR);
	current_position(*head_a);
	current_position(*head_b);
}
