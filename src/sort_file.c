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

int				reverse_two_file(t_file *before, t_file *after, t_file **begin)
{
	t_file *cpy;
	t_file *tmp;
	t_file *scndbfr;

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
	return (sort_by_alpha_file(tmp, begin));
}

void			place_at_the_beginning(t_file *file, t_file **begin,\
				t_file *next, t_file *make_it_before)
{
	struct stat tmp;

	lstat(next->name, &tmp);
	while (next && next != file && S_ISDIR(tmp.st_mode) == 0)
	{
		next = next->next;
		lstat(next->name, &tmp);
	}
	if (next && ft_strcmp(next->name, file->name) != 0)
	{
		while (make_it_before->next != file)
			make_it_before = make_it_before->next;
		make_it_before->next = file->next;
		make_it_before = *begin;
		file->next = next;
		if (*begin == next)
		{
			*begin = file;
			return ;
		}
		while (make_it_before && make_it_before->next != next)
			make_it_before = make_it_before->next;
		if (make_it_before)
			make_it_before->next = file;
	}
}

int				sort_by_type(t_file *file, t_file **begin)
{
	t_file		*next;
	struct stat tmp;
	t_file		*lol;

	if (!file)
		return (1);
	lstat(file->name, &tmp);
	if (S_ISDIR(tmp.st_mode) != 0)
		return (sort_by_type(file->next, begin));
	place_at_the_beginning(file, begin, *begin, *begin);
	lol = file->next;
	return (sort_by_type(file->next, begin));
}

int				sort_by_alpha_file(t_file *file, t_file **begin)
{
	t_file *next;

	next = *begin;
	if (!file)
		return (1);
	while (next && ft_strcmp(next->name, file->name) < 0)
		next = next->next;
	if (ft_strcmp(next->name, file->name) == 0 && next == file)
		return (sort_by_alpha_file(file->next, begin));
	else
		return (reverse_two_file(next, file, begin));
}

void			reverse_sort_file(t_file **begin)
{
	t_file *cpy;
	t_file *next;
	t_file *bfr;

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
