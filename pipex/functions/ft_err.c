/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:24:53 by ymirna            #+#    #+#             */
/*   Updated: 2022/02/23 21:41:42 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void	ft_free_arr(char	**arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int	ft_file_err(t_pipe	*st)
{
	if (st->f1 < 0)
	{
		perror("File_1 error");
		return (2);
	}
	perror("File_2 error");
	return (3);
}
