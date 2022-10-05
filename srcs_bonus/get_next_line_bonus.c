/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:55:10 by jiyun             #+#    #+#             */
/*   Updated: 2022/10/05 10:57:20 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char    *backup_line(char *keep, char **ret_from_outside)
{
    char    *ptr_newline;
    char    *ret;

    ptr_newline = ft_strchr(keep, '\n');
    if (!ptr_newline || *(ptr_newline + 1) == '\0')
    {
        free(keep);
        keep = NULL;
        return (NULL);
    }
    ret = ft_strdup(ptr_newline + 1);
    if (!ret)
	{
        free(*ret_from_outside);
        *ret_from_outside = NULL;
    }
    free(keep);
    return (ret);
}

static char    *get_line(char *keep)
{
    char    *ptr_newline;
    char    *ret;
    ssize_t i;

    if (*keep == '\0')
        return (NULL);
    ptr_newline = ft_strchr(keep, '\n');
    if (!ptr_newline)
        return (ft_strdup(keep));
    ret = malloc(sizeof(char) * (ptr_newline - keep + 2));
    if (!ret)
        return (NULL);
    i = 0;
    while (i < ptr_newline - keep + 1)
    {
        ret[i] = keep[i];
        i++;
    }
    ret[i] = '\0';
    return (ret);
}

static char    *read_and_put(int fd, char *keep)
{
    ssize_t read_byte;
    char    *buf;

    buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!buf)
        return (NULL);
    read_byte = read(fd, buf, BUFFER_SIZE);
    while (read_byte > 0)
    {
        buf[read_byte] = '\0';
        keep = ft_strjoin(keep, buf);
        if (ft_strchr(keep, '\n') || !keep)
			break ;
        read_byte = read(fd, buf, BUFFER_SIZE);
    }
    free(buf);
    buf = NULL;
    if (read_byte < 0 || !keep)
		return (NULL);
    return (keep);
}

static t_fd_lst    *find_fd(int fd, t_fd_lst *head)
{
    t_fd_lst    *target;

    target = head->next;
    while(target)
    {
        if (target->fd == fd)
            return (target);
        target = target->next;
    }
    target = malloc(sizeof(t_fd_lst));
    if (!target)
        return (NULL);
    target->fd = fd;
    target->keep = NULL;
    target->prev = head;
    target->next = head->next;
    if (head->next)
        head->next->prev = target;
    head->next = target;
    return (target);
}

char    *get_next_line(int fd)
{
    static t_fd_lst head;
    t_fd_lst        *node;
    char            *ret;

    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    node = find_fd(fd, &head);
    if (!node)
        return (NULL);
    node->keep = read_and_put(fd, node->keep);
    if(!(node->keep))
    {
        free_clean(node);
        return (NULL);
    }
    ret = get_line(node->keep);
    if (!ret)
	{
        free(node->keep);
        free_clean(node);
        return (NULL);
    }
    node->keep = backup_line(node->keep, &ret);
    return (ret);
}
