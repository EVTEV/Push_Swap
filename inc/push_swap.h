#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../Libft/inc/libft.h"

typedef struct	s_node
{
	int	value;
	int	index;
	struct	s_node	*next;
}	t_node;

typedef struct	s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

// ---------- Stack ---------- //
t_stack	*init_stack(void);
void    fill_stack(t_stack *stack, int value);
void    free_stack(t_stack *stack);

// ---------- Pars ---------- //
int     ft_atoi(const char *str);
int		is_number(char *str);
void	check_dup(t_stack *stack);
void	do_split(char **av, t_stack *a);
void	fill_good(int ac, char **av, t_stack *a);

// ---------- Move ---------- //
void    pa(t_stack *a, t_stack *b);
void    pb(t_stack *a, t_stack *b);
void    sa(t_stack *a);
void    sb(t_stack *b);
void    ss(t_stack *a, t_stack *b);
void    rotate(t_stack *stack);
void    ra(t_stack *a);
void    rb(t_stack *b);
void    rr(t_stack *a, t_stack *b);
void    reverse(t_stack *stack);
void    rra(t_stack *a);
void    rrb(t_stack *b);
void    rrr(t_stack *b, t_stack *a);

// ---------- Node ---------- //
t_node	*get_max_node(t_stack *stack);
t_node	*get_min_node(t_stack *stack);
void	move_to_top(t_stack *stack, t_node *target);

// ---------- Algo ---------- //
void    sort_three(t_stack *a);
void	sort_stack(t_stack *a, t_stack *b);
void	push_swap(t_stack *a, t_stack *b);

// ---------- Utils ---------- //
int     is_sorted(t_stack *stack);
void    index_stack(t_stack *stack);
void	normalize_stack(t_stack *stack);
void    error_exit(void);

#endif
