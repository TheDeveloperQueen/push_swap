/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivasque <rivasque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:00:50 by rivasque          #+#    #+#             */
/*   Updated: 2023/12/14 11:21:05 by rivasque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdbool.h>

# define RR 0
# define RA 1
# define RB 2
# define RRR 3
# define RRA 4
# define RRB 5

typedef struct s_stack
{
	int				nbr;
	int				position;
	int				cost;
	bool			cheap;
	bool			above_medium;
	struct s_stack	*next;
	struct s_stack	*target;
}					t_stack;	

void	add_end(t_stack **stack, int nbr);
t_stack	*create_stack_argv_one(char **array);
t_stack	*create_stack_argv(char **array, int argc);
void	free_array(char **array);
void	free_stack(t_stack *head);
int		rep(char **array, int n);
int		dig(char **array, int n);
int		stack_size(t_stack *head);
void	delete_1st(t_stack **head);
void	sa(t_stack *head);
void	sb(t_stack *head);
void	ss(t_stack *head_a, t_stack *head_b);
void	pb(t_stack **head_a, t_stack **head_b);
void	pa(t_stack **head_a, t_stack **head_b);
void	ra(t_stack **head);
void	rb(t_stack **head);
void	print_mov_rr(t_stack **head_a, t_stack **head_b, int move);
void	rra(t_stack **head);
void	rrb(t_stack **head);
void	print_mov_rrr(t_stack **head_a, t_stack **head_b, int move);
t_stack	*sort_stack(t_stack **head_a, t_stack **head_b);
int		ntg(char **argv);
void	sort_2(t_stack **head);
void	sort_3(t_stack **head);
void	sort_4(t_stack **head_a, t_stack **head_b);
void	sort_5(t_stack **head_a, t_stack **head_b);
void	sort_many(t_stack **head_a, t_stack **head_b);
bool	stack_sorted(t_stack *head);
void	find_cheap(t_stack *head);
void	target_a(t_stack *head_a, t_stack *head_b);
void	target_b(t_stack *head_a, t_stack *head_b);
t_stack	*find_smallest(t_stack *head);
t_stack	*find_max(t_stack *head);
void	check_push_a(t_stack **head_a, t_stack **head_b, t_stack *top);
void	check_push_b(t_stack **head_a, t_stack **head_b, t_stack *top);
void	move_both_rr(t_stack **head_a, t_stack **head_b, t_stack *cheapest);
void	move_both_rrr(t_stack **head_a, t_stack **head_b, t_stack *cheapest);
void	current_position(t_stack *head);
t_stack	*get_cheap(t_stack *head);
void	init_a(t_stack *head_a, t_stack *head_b);
void	init_b(t_stack *head_a, t_stack *head_b);
void	min_top(t_stack **head_a, t_stack **head_b);
void	move_b_to_a(t_stack **head_a, t_stack **head_b);
void	move_a_to_b(t_stack **head_a, t_stack **head_b);
int		find_min_pos(t_stack **head);
void	cost_to_move(t_stack *head_a, t_stack *head_b);
void	exit_error(void);

#endif