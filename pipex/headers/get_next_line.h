/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 08:22:56 by ymirna            #+#    #+#             */
/*   Updated: 2022/02/23 21:14:09 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_gnl
{
	int		line;
	int		fd;
	char	*str;
	size_t	chr;
	size_t	i;
}	t_gnl;

int		get_next_line(int fd_0, int fd_f, char	*limiter);
size_t	ft_strlen(const char	*s);
char	*ft_sub(char *s, unsigned int start, size_t	len, int x);
char	*ft_join(char *s1, char *s2, int x);
int		ft_strncmp(const char	*s1, const char	*s2, int x);

#endif