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

int		for_size(char *str, long *block, int *block_max)
{
	struct stat for_size;
	int			i;
	int			tmp;
	long		block_lol;

	lstat(str, &for_size);
	i = count(for_size.st_size);
	block_lol = for_size.st_blocks;
	tmp = count(block_lol);
	if (tmp > *block_max)
		*block_max = tmp;
	*block = *block + block_lol;
	return (i);
}

int		for_link(char *str)
{
	struct stat for_link;
	int			i;

	lstat(str, &for_link);
	i = count(for_link.st_nlink);
	return (i);
}

int		max_size_check(t_directory *dir, char *path,\
		t_command *command_list, int *block_max)
{
	int		i;
	int		g;
	char	*new_name;
	long	block;

	block = 0;
	i = 1;
	while (dir)
	{
		if (can_we_open(dir->d_name, command_list) == 1)
		{
			new_name = add_name(path, dir->d_name);
			g = for_size(new_name, &block, block_max);
			if (g > i)
				i = g;
			free(new_name);
		}
		dir = dir->next;
	}
	if (check(command_list, 'l'))
		ft_printf("total %ld\n", block);
	return (i);
}

int		max_link_check(t_directory *dir, char *path)
{
	int		g;
	int		i;
	char	*new_name;

	g = 0;
	i = 1;
	while (dir)
	{
		new_name = add_name(path, dir->d_name);
		g = for_link(new_name);
		if (g > i)
			i = g;
		dir = dir->next;
		free(new_name);
	}
	return (i);
}
