/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:57:29 by bel-abde          #+#    #+#             */
/*   Updated: 2025/02/17 14:08:03 by bel-abde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				i;
	int				data;
	struct s_list	*next;
}	t_list;

// Operations
void	ra(t_list **stack_a, int flag);
void	rb(t_list **stack_b, int flag);
void	rr(t_list **s_a, t_list **s_b, int flag);
void	rra(t_list **stack_a, int flag);
void	rrb(t_list **stack_b, int flag);
void	rrr(t_list **s_a, t_list **s_b, int flag);
void	sa(t_list **stack_a, int flag);
void	sb(t_list **stack_b, int flag);
void	ss(t_list **s_a, t_list **s_b, int flag);
void	add_front(t_list **lst, t_list *new);
void	pa(t_list **s_a, t_list **s_b, int flag);
void	pb(t_list **s_a, t_list **s_b, int flag);
t_list	*new_node(int data);
void	add_back(t_list **lst, t_list *new);
int		size_lst(t_list *lst);
void	clear_all(t_list **lst);
t_list	*last_lst(t_list *lst);
int		parsing(char *str, t_list **stack_a);
int		check_num(char *str);
int		check_duplicate(t_list *stack_a);
void	clear_result(char **result);
int		is_sorted(t_list *stack_a);
void	sort_three(t_list **stack_a);
void	sort_four(t_list **stack_a, t_list **stack_b);
void	sort_five(t_list **stack_a, t_list **stack_b);
int		get_min(t_list *stack);
void	multi_move(t_list **stack, char *move, int count);
int		get_my_range(int size);
int		get_max_pos(t_list *stack);
void	push_to_b(t_list **stack_a, t_list **stack_b, int min, int max);
void	push_to_a(t_list **stack_a, t_list **stack_b);
void	big_sort(t_list **stack_a, t_list **stack_b);
t_list	*lst_clone(t_list *lst);
void	del_max(t_list **clone, t_list *max);
void	find_max(t_list **original, t_list **clone, int *index);
void	assign_index(t_list **lst);
 int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
long	ft_atoi(char *str, t_list **stack_a, char **result);

void	ft_checker(t_list **stack_a, t_list **stack_b);
void	make_moves(t_list **stack_a, t_list **stack_b, char *operation);
int		ft_strcmp(char *s1, char *s2);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);

#endif