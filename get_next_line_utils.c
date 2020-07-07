/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sookim <sookim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 15:01:17 by sookim            #+#    #+#             */
/*   Updated: 2020/07/07 15:27:39 by sookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t      ft_strlen(const char *s)
{
    size_t  i;
    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

size_t      ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t  i;
    i = 0;
    if (size == 0)
        return (ft_strlen(src));
    while (src[i] != '\0' && i < size - 1)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = 0;
    return (ft_strlen(src));    
}

size_t      ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t  i;
    size_t  dst_len;
    size_t  src_len;
    
    i = 0;
    dst_len = ft_strlen(dst);
    src_len = ft_strlen(src);
    while (src[i] != '\0' && i < size - 1 - dst_len)
    {
        dst[dst_len + i] = src[i];
        i++;
    }
    dst[dst_len + i] = '\0';
    if (size < dst_len)
        return (src_len + size);
    return (src_len + dst_len);
}

char    *ft_strjoin(char *s1, char *s2)
{
    char    *ptr;
    size_t  s1_len;
    size_t  s2_len;

    if (!s1 && !s2)
        return (NULL);
    if (!s1)
        return ((char *)s2);
    if (!s2)
        return ((char *)s1);
    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);
    if (!(ptr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))));
        return (NULL);
    ft_strlcpy(ptr, s1, s1_len + 1);
    free(s1);
    ft_strlcat(ptr + (s1_len), s2, s2_len + 1);
    return (ptr);
}

char    *ft_strdup(const char *s)
{
    char    *result;
    size_t  i;
    
    i = ft_strlen(s);
    result = (char *)malloc(sizeof(char) * (i + 1));
    if (!result)
        return (NULL);
    i = 0;
    while (s[i])
    {
        result[i] = s[i];
        i++;
    }
    result[i] = '\0';
    return (result);    
}