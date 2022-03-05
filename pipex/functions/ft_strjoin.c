/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:10:59 by ymirna            #+#    #+#             */
/*   Updated: 2022/02/13 19:58:26 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

static size_t	ft_strlcpy(char	*dst, const char	*src, size_t	size)
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

static size_t	ft_strlcat(char	*dst, const char	*src, size_t	size)
{
	size_t	i;
	size_t	j;
	size_t	lend;
	size_t	lens;

	i = 0;
	lend = ft_strlen(dst);
	lens = ft_strlen(src);
	j = lend;
	if (lend > size)
		lend = size;
	if (lend < size - 1 && size > 0)
	{
		while (lend + i < size - 1 && src[i])
		{
			dst[j] = src[i];
			j++;
			i++;
		}
		dst[j] = '\0';
	}
	return (lend + lens);
}

char	*ft_strjoin(char *s1, char const	*s2, int x)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
		return (ft_substr(s2, 0, ft_strlen(s2)));
	if (!s2)
		return (ft_substr(s1, 0, ft_strlen(s1)));
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, i + 1);
	ft_strlcat(str, s2, i + j + 1);
	if (x == 1)
		free(s1);
	return (str);
}
