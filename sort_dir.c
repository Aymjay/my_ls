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

int		reverse_two(t_directory *before, t_directory *after,\
		t_directory **begin)
{
	t_directory *cpy;
	t_directory *tmp;
	t_directory *scndbfr;

	tmp = after->next;
	cpy = *begin;
	scndbfr = *begin;
	while (scndbfr->next != after && scndbfr->next)
		scndbfr = scndbfr->next;
	if (cpy != before)
	{
		while (cpy->next != before && cpy->next)
			cpy = cpy->next;
		cpy->next = after;
	}
	else
		*begin = after;
	scndbfr->next = after->next;
	after->next = before;
	return (sort_by_alpha(tmp, begin));
}

int		reverse_two_time(t_directory *before, t_directory *after,\
		t_directory **begin)
{
	t_directory *cpy;
	t_directory *tmp;
	t_directory *scndbfr;

	tmp = after->next;
	cpy = *begin;
	scndbfr = *begin;
	while (scndbfr->next != after && scndbfr->next)
		scndbfr = scndbfr->next;
	if (cpy != before)
	{
		while (cpy->next != before && cpy->next)
			cpy = cpy->next;
		cpy->next = after;
	}
	else
		*begin = after;
	scndbfr->next = after->next;
	after->next = before;
	return (sort_by_time(tmp, begin));
}

int		sort_by_alpha(t_directory *dir, t_directory **begin)
{
	t_directory *next;

	next = *begin;
	if (!dir)
		return (1);
	while (next && ft_strcmp(next->d_name, dir->d_name) < 0)
		next = next->next;
	if (ft_strcmp(next->d_name, dir->d_name) == 0)
		return (sort_by_alpha(dir->next, begin));
	else
		return (reverse_two(next, dir, begin));
}

int		cmp_time(time_t src, char *str)
{
	struct stat other;

	stat(str, &other);
	if (src <= other.st_mtime)
		return (1);
	else
		return (0);
}

int		sort_by_time(t_directory *dir, t_directory **begin)
{
	struct stat src;
	t_directory *next;

	if (!dir)
		return (1);
	next = *begin;
	stat(dir->d_name, &src);
	while (next && cmp_time(src.st_mtime, next->d_name) == 1 &&\
		ft_strcmp(next->d_name, dir->d_name) != 0)
		next = next->next;
	if (ft_strcmp(next->d_name, dir->d_name) == 0)
		return (sort_by_time(dir->next, begin));
	else
		return (reverse_two_time(next, dir, begin));
}
