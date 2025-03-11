/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-abde <bel-abde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 09:37:01 by bel-abde          #+#    #+#             */
/*   Updated: 2024/11/24 09:41:36 by bel-abde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*read_line(int fd, char *stash, int bytes_read);
char	*get_my_line(char *stash, int i);
char	*modify_stash(char *stash, int i);
int		ft_strlen(char *str);
char	*ft_strjoin(char *stash, char *buffer);
char	*ft_strchr(char *str, int c);
void	free_all(char *stash, char *buffer);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(char *s1);

#endif