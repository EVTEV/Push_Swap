/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaes <acaes@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:15:45 by acaes             #+#    #+#             */
/*   Updated: 2025/02/12 09:15:45 by acaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/inc/libft.h"

typedef struct s_pos
{
	int	pos_a;
	int	pos_b;
}	t_pos;

typedef struct s_cost
{
	int cost_a;
	int cost_b;
	int total;
}	t_cost;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

// ---------- Stack ---------- //
t_stack	*init_stack(void);
void	fill_stack(t_stack *stack, int value);
void	free_stack(t_stack *stack);

// ---------- Pars ---------- //
long	ft_atol(const char *str);
int		is_number(char *str);
int		check_dup(t_stack *stack);
void	do_split(char **av, t_stack *a, t_stack *b);
void	fill_good(int ac, char **av, t_stack *a, t_stack *b);

// ---------- Move ---------- //
// _____pushy.c_____ //
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
// _____swapy.c_____ //
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
// _____rotate.c_____ //
void	rotate(t_stack *stack);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
// _____reverse.c_____ //
void	reverse(t_stack *stack);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *b, t_stack *a);

// ---------- Node ---------- //
// _____get_node.c_____ //
t_node	*get_max_node(t_stack *stack);
t_node	*get_min_node(t_stack *stack);
// _____use_node.c_____ //
int		get_node_position(t_stack *stack, t_node *target);
t_node	*find_node_by_value(t_stack *stack, int value);

// ---------- Algo ---------- //
// _____sort_small.c_____ //
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
// _____best_place.c_____ //
t_node	*find_target_position(t_stack *a, int value);
// _____calc_cost.c_____ //
t_node	*find_best_node(t_stack *a, t_stack *b);
// _____exec_move.c_____ //
void	execute_move(t_stack *a, t_stack *b, t_node *node);
// _____quick_sort.c_____ //
void	quick_sort(int *arr, int low, int high);
// _____push_swap.c_____ //
void	sort_small(t_stack *a, t_stack *b);
void	sort_stack(t_stack *a, t_stack *b);
void	push_swap(t_stack *a, t_stack *b);

// ---------- Utils ---------- //
int		get_chunk_size(int size);
int		is_sorted(t_stack *stack);
void	align_stack(t_stack *a);
void	msg_error(t_stack *a, t_stack *b);
void	free_error(char **tab, t_stack *a, t_stack *b);

#endif
