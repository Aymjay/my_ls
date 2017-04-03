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

void			one_cpy(struct dirent *src, t_directory **begin)
{
	t_directory *next;
	t_directory *cpy;

	cpy = malloc(sizeof(t_directory));
	next = *begin;
	while (next->next)
		next = next->next;
	cpy->d_ino = src->d_ino;
	cpy->d_reclen = src->d_reclen;
	cpy->d_type = src->d_type;
	cpy->d_name = ft_strdup(src->d_name);
	cpy->next = NULL;
	next->next = cpy;
}

t_directory		*dirent_cpy(DIR *file)
{
	t_directory		*cpy;
	struct dirent	*tmp;
	t_directory		*lol;

	cpy = malloc(sizeof(t_directory));
	cpy->next = NULL;
	tmp = readdir(file);
	while (tmp)
	{
		one_cpy(tmp, &cpy);
		tmp = readdir(file);
	}
	lol = cpy;
	cpy = cpy->next;
	free(lol);
	return (cpy);
}
