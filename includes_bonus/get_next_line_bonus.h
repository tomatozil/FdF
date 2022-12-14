/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:10:23 by jiyun             #+#    #+#             */
/*   Updated: 2022/10/05 12:39:28 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# define BUFFER_SIZE 42

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_fd_lst
{
	int				fd;
	char			*keep;
	struct s_fd_lst	*prev;
	struct s_fd_lst	*next;
}	t_fd_lst;

char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
void	free_clean(t_fd_lst *node);

#endif
