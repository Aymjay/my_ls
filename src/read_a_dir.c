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

static int		check_three(t_command *command_list)
{
	int i;

	i = 0;
	i = check(command_list, 'l') + check(command_list, 'o')\
	+ check(command_list, 'g');
	return (i);
}

void			aff_name(t_directory *dir, char *path, int l)
{
	struct stat tmp;
	ssize_t		r;
	char		*linkname;

	lstat(path, &tmp);
	if (S_ISLNK(tmp.st_mode) == 1)
	{
		ft_printf("%s", dir->d_name);
		linkname = malloc(tmp.st_size + 1);
		r = readlink(path, linkname, tmp.st_size + 1);
		linkname[r] = '\0';
		ft_printf(" -> %s\n", linkname);
		free(linkname);
	}
	else
		ft_printf("%s\n", dir->d_name);
}

int				read_a_dir_lol(t_directory *dir,\
				t_command *command_list, char *path)
{
	int		i;
	int		g;
	int		block_max;
	char	*new_name;

	block_max = 0;
	i = max_size_check(dir, path, command_list, &block_max);
	g = max_link_check(dir, path);
	while (dir)
	{
		if (can_we_open(dir->d_name, command_list) == 1)
		{
			new_name = add_name(path, dir->d_name);
			other_command(new_name, command_list, block_max);
			if ((check_three(command_list)) > 0)
				aff_rights(new_name, i, command_list, g);
			if (check(command_list, 'c') == 1)
				add_color_file(dir, new_name, check(command_list, 'l'));
			else
				aff_name(dir, new_name, check(command_list, 'l'));
			free(new_name);
		}
		dir = dir->next;
	}
	return (1);
}
