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
void	move_to_top(t_stack *stack, t_node *target);

// ---------- Algo ---------- //
// _____sort_small.c_____ //
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
// _____sort_chunk.c_____ //
int		get_chunk_size(int	size);
// _____push_swap.c_____ //
void	sort_small(t_stack *a, t_stack *b);
//void	sort_chunk(t_stack *a, t_stack *b);
void	push_swap(t_stack *a, t_stack *b);

// ---------- Utils ---------- //
int		is_sorted(t_stack *stack);
void	normalize_stack(t_stack *stack);
void	msg_error(t_stack *a, t_stack *b);

#endif
