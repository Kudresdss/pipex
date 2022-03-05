/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 08:26:20 by ymirna            #+#    #+#             */
/*   Updated: 2022/02/13 20:34:52 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"

size_t	ft_strlen(const char	*s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (len);
	while (s[len])
	{
		len++;
	}
	return (len);
}

size_t	ft_strlcpy(char	*dst, const char	*src, size_t	size)
{
	size_t	i;
	size_t	lens;

	i = 0;
	lens = ft_strlen(src);
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (lens);
}

void	ft_strlcat(char	*dst, const char	*src, size_t	size)
{
	size_t	i;
	size_t	j;
	size_t	lend;

	if (!src)
		return ;
	i = 0;
	lend = ft_strlen(dst);
	j = lend;
	if (lend > size)
		lend = size;
	if (lend < size - 1 && size > 0)
	{
		while (lend + i < size - 1 && src[i])
			dst[j++] = src[i++];
		dst[j] = '\0';
	}
}

char	*ft_sub(char *s, unsigned int start, size_t	len, int x)
{
	char	*str;
	size_t	i;
	size_t	lens;

	i = 0;
	if (!s)
		return (NULL);
	lens = ft_strlen(s);
	if (len > lens)
		len = lens;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		if (start >= lens)
			break ;
		str[i++] = s[start++];
	}
	str[i] = '\0';
	if (x == 1)
		free (s);
	return (str);
}

char	*ft_join(char *s1, char *s2, int x)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 && x == 0)
		return (ft_sub(s2, 0, ft_strlen(s2), 0));
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, i + 1);
	ft_strlcat(str, s2, i + j + 1);
	if (s1)
		free(s1);
	if (x == 1)
		free(s2);
	return (str);
}
