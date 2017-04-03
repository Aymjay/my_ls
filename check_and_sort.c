/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   applying.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darabi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 19:39:50 by darabi            #+#    #+#             */
/*   Updated: 2016/02/22 19:41:02 by darabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	reverse_sort(t_directory **begin)
{
	t_directory *cpy;
	t_directory *next;
	t_directory *bfr;

	bfr = *begin;
	cpy = bfr->next;
	bfr->next = NULL;
	while (cpy)
	{
		next = cpy->next;
		cpy->next = bfr;
		bfr = cpy;
		cpy = next;
	}
	*begin = bfr;
}

int		check(t_command *list, char c)
{
	while (list)
	{
		if (list->letter == c)
			return (1);
		list = list->next;
	}
	return (0);
}
