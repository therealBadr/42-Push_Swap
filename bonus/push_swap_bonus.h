/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:56:19 by bel-abde          #+#    #+#             */
/*   Updated: 2025/03/12 22:15:59 by bel-abde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				i;
	int				data;
	struct s_list	*next;
}	t_list;

void	ft_checker(t_list **stack_a, t_list **stack_b);
void	make_moves(t_list **stack_a, t_list **stack_b, char *operation);
int		ft_strcmp(char *s1, char *s2);
char	*get_next_line(int fd);
void	free_all(char *stash, char *buffer);
char	*read_line(int fd, char *stash, int bytes_read);
char	*get_my_line(char *stash, int i);
char	*modify_stash(char *stash, int i);
int		ft_strlen(char *str);
char	*ft_strjoin(char *stash, char *buffer);
char	*ft_strchr(char *str, int c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(char *s1);
int		is_sorted(t_list *stack_a);
void	clear_result(char **result);
int		check_duplicate(t_list *stack_a);
int		parsing(char *str, t_list **stack_a);
int		check_num(char *str);
t_list	*new_node(int data);
void	add_back(t_list **lst, t_list *new);
int		size_lst(t_list *lst);
void	clear_all(t_list **lst);
char	**ft_split(char const *s, char c);
long	ft_atoi(char *str, t_list **stack_a, char **result);
// t_list	*last_lst(t_list *lst);
void	add_front(t_list **lst, t_list *new);
void	pa(t_list **stack_a, t_list **stack_b, int flag);
void	pb(t_list **stack_a, t_list **stack_b, int flag);
void	ra(t_list **stack_a, int flag);
void	rb(t_list **stack_b, int flag);
void	rr(t_list **s_a, t_list **s_b, int flag);
void	rra(t_list **stack_a, int flag);
void	rrb(t_list **stack_b, int flag);
void	rrr(t_list **s_a, t_list **s_b, int flag);
void	sa(t_list **stack_a, int flag);
void	sb(t_list **stack_b, int flag);
void	ss(t_list **s_a, t_list **s_b, int flag);

#endif