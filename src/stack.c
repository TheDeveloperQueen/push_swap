/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivasque <rivasque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:27:57 by rivasque          #+#    #+#             */
/*   Updated: 2023/12/14 11:19:24 by rivasque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Add node at end of the list
void	add_end(t_stack **head, int nbr)
{
	t_stack	*new;
	t_stack	*current;

	current = *head;
	new = (t_stack *) malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->nbr = nbr;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}

//Delete 1st node
void	delete_1st(t_stack **head)
{
	t_stack	*temp;

	temp = *head;
	*head = (*head)->next;
	free(temp);
}

t_stack	*create_stack_argv_one(char **array)
{
	int		i;
	t_stack	*stack;

	i = 0;
	stack = NULL;
	while (array[i])
	{
		add_end(&stack, ft_atoi(array[i]));
		i++;
	}
	return (stack);
}

t_stack	*create_stack_argv(char **array, int argc)
{
	int		i;
	t_stack	*stack;

	i = 1;
	stack = NULL;
	while (i < argc)
	{
		add_end(&stack, ft_atoi(array[i]));
		i++;
	}
	return (stack);
}

//Refresh @ each movement
void	init_a(t_stack *head_a, t_stack *head_b)
{
	current_position(head_a);
	current_position(head_b);
	target_a(head_a, head_b);
	cost_to_move(head_a, head_b);
	find_cheap(head_a);
}
