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

int		count(off_t size)
{
	int i;

	i = 0;
	if (size == 0)
		size = 1;
	while (size != 0)
	{
		++i;
		size = size / 10;
	}
	return (i);
}

void	aff_size(off_t size, int max_size)
{
	int i;
	int count_s;

	count_s = 0;
	i = count(size);
	i = max_size - i;
	while (count_s < i)
	{
		ft_printf(" ");
		++count_s;
	}
	ft_printf("%ld ", size);
}

int		aff_users(struct stat user, int i, t_command *command_list, int g)
{
	struct passwd	*uid;
	struct group	*gid;

	aff_size(user.st_nlink, g);
	uid = getpwuid(user.st_uid);
	gid = getgrgid(user.st_gid);
	if (check(command_list, 'g') == 0)
		ft_printf("%s  ", uid->pw_name);
	if (check(command_list, 'o') == 0)
		ft_printf("%s  ", gid->gr_name);
	if (S_ISCHR(user.st_mode) == 1 || S_ISBLK(user.st_mode) == 1)
	{
		ft_printf("%ld, ", major(user.st_rdev));
		ft_printf("%ld ", minor(user.st_rdev));
	}
	else
		aff_size(user.st_size, i);
	time_read(user, 0, 0);
	return (1);
}
