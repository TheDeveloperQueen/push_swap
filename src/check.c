/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivasque <rivasque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:37:42 by rivasque          #+#    #+#             */
/*   Updated: 2023/12/14 11:20:44 by rivasque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

//check duplicates
int	rep(char **array, int n)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < n)
	{
		j = i + 1;
		while (array[j])
		{
			if (ft_atoi(array[i]) == ft_atoi(array[j]))
				count++;
			j++;
		}
		i++;
	}
	if (count > 0)
		return (0);
	else
		return (1);
}

//check digits
int	dig(char **array, int n)
{
	int	i;
	int	flag;

	i = 0;
	while (i < n)
	{
		ft_strict_atoi(array[i], &flag);
		if (!is_numeric(array[i]) || flag == -1)
			return (0);
		i++;
	}
	return (1);
}

// Check if empty
int	ntg(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

// Make sure target and cheap are on top of the stack 
// (top can be cheapest ot target)
void	check_push_a(t_stack **head_a, t_stack **head_b, t_stack *top)
{
	while (*head_a != top)
	{
		if (top->above_medium)
			print_mov_rr(head_a, head_b, RA);
		else
			print_mov_rrr(head_a, head_b, RRA);
	}
}

void	check_push_b(t_stack **head_a, t_stack **head_b, t_stack *top)
{
	while (*head_b != top)
	{
		if (top->above_medium)
			print_mov_rr(head_a, head_b, RB);
		else
			print_mov_rrr(head_a, head_b, RRB);
	}
}
