/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <aabouibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:07:20 by msidqi            #+#    #+#             */
/*   Updated: 2019/10/06 17:50:58 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_tab(char ***tab)
{
	int i;

	if (!tab)
		return ;
	i = -1;
	while ((*tab)[++i])
	{
		if ((*tab)[i] != NULL)
			ft_strdel(&(*tab)[i]);
	}
	free((*tab));
	*tab = NULL;
}
