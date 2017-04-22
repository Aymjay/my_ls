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

void	color_file_second(struct stat tmp, t_directory *dir)
{
	if ((tmp.st_mode & S_IXUSR) == 64 || (tmp.st_mode & S_IXGRP) == 8 ||\
		(tmp.st_mode & S_IXOTH) == 1)
		ft_printf("\033[31m%s\033[00m\n", dir->d_name);
	else if (S_ISBLK(tmp.st_mode) == 1)
		ft_printf("{green}%s{eoc}\n", dir->d_name);
	else if (S_ISSOCK(tmp.st_mode) == 1)
		ft_printf("{blue}%s{eoc}\n", dir->d_name);
	else if (S_ISFIFO(tmp.st_mode) == 1)
		ft_printf("{brown}%s{eoc}\n", dir->d_name);
	else if (S_ISCHR(tmp.st_mode) == 1)
		ft_printf("\033[33m%s{eoc}\n", dir->d_name);
	else
		ft_printf("%s\n", dir->d_name);
}

void	add_color_file(t_directory *dir, char *path, int l)
{
	struct stat tmp;
	ssize_t		r;
	char		*linkname;

	lstat(path, &tmp);
	if (S_ISDIR(tmp.st_mode) == 1)
		ft_printf("{teal}%s{eoc}\n", dir->d_name);
	else if (S_ISLNK(tmp.st_mode) == 1)
	{
		ft_printf("{purple}%s{eoc}", dir->d_name);
		if (l == 0)
		{
			ft_printf("\n");
			return ;
		}
		linkname = malloc(tmp.st_size + 1);
		r = readlink(path, linkname, tmp.st_size + 1);
		linkname[r] = '\0';
		ft_printf(" -> %s\n", linkname);
		free(linkname);
	}
	else
		color_file_second(tmp, dir);
}
