/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivasque <rivasque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:33:15 by ritavasques       #+#    #+#             */
/*   Updated: 2023/12/13 14:58:10 by rivasque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *head)
{
	int	i;

	i = 0;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}

int	find_min_pos(t_stack **head)
{
	int		min;
	int		min_pos;
	int		i;
	t_stack	*aux;

	i = 0;
	min_pos = 0;
	aux = *head;
	min = INT_MAX;
	while ((aux))
	{
		if (min > (aux)->nbr)
		{
			min = (aux)->nbr;
			min_pos = i;
		}
		i++;
		aux = aux->next;
	}
	return (min_pos);
}

void	current_position(t_stack *head)
{
	int	i;
	int	medium;

	i = 0;
	if (!head)
		return ;
	medium = stack_size(head) / 2;
	while (head)
	{
		head->position = i;
		if (i <= medium)
			head->above_medium = true;
		else
			head->above_medium = false;
		head = head->next;
		++i;
	}
}

t_stack	*find_smallest(t_stack *head)
{
	long	smallest_value;
	t_stack	*smallest;

	smallest_value = LONG_MAX;
	if (!head)
		return (NULL);
	while (head)
	{
		if (head->nbr < smallest_value)
		{
			smallest_value = head->nbr;
			smallest = head;
		}
		head = head->next;
	}
	return (smallest);
}

t_stack	*find_max(t_stack *head)
{
	long	max_value;
	t_stack	*max;

	max_value = LONG_MIN;
	if (!head)
		return (NULL);
	while (head)
	{
		if (head->nbr > max_value)
		{
			max_value = head->nbr;
			max = head;
		}
		head = head->next;
	}
	return (max);
}
