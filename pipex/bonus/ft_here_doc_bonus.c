/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:10:21 by ymirna            #+#    #+#             */
/*   Updated: 2022/03/05 15:18:16 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex_bonus.h"
#include "../headers/get_next_line.h"

void	ft_here_doc(t_pipe	*st, int ac, char	**av)
{
	st->here_d++;
	st->f1 = open("to_append.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (st->f1 < 0)
		exit(8);
	st->f2 = open(av[ac - 1], O_CREAT | O_RDWR | O_APPEND, 0644);
	while (1)
	{
		write(1, "pipe heredoc>", 13);
		if (get_next_line(0, st->f1, av[2]) < 0)
			break ;
	}
	close(st->f1);
	st->f1 = open("to_append.txt", O_RDONLY);
}
