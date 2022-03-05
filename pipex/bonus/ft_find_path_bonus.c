/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 22:44:16 by ymirna            #+#    #+#             */
/*   Updated: 2022/02/13 16:47:05 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex_bonus.h"

char	*ft_substr(char const *s, unsigned int start, size_t	len)
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
	return (str);
}

static void	ft_add_slash(char **path)
{
	size_t	i;

	i = 0;
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/", 1);
		i++;
	}
}

char	**ft_find_path(char	**env)
{
	size_t	i;
	size_t	y;
	char	*sustr;
	char	**path;

	i = 0;
	y = 5;
	while (env[i])
	{
		if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T' &&
			env[i][3] == 'H' && env[i][4] == '=')
		{
			while (env[i][y])
			{
				y++;
			}
			break ;
		}
		i++;
	}
	sustr = ft_substr(env[i], 5, y - 5);
	path = ft_split(sustr, ':');
	free(sustr);
	ft_add_slash(path);
	return (path);
}
