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

void	aff_type(mode_t user)
{
	if (S_ISLNK(user) == 1)
		ft_printf("l");
	else if (S_ISDIR(user) == 1)
		ft_printf("d");
	else if (S_ISBLK(user) == 1)
		ft_printf("b");
	else if (S_ISSOCK(user) == 1)
		ft_printf("s");
	else if (S_ISFIFO(user) == 1)
		ft_printf("p");
	else if (S_ISCHR(user) == 1)
		ft_printf("c");
	else
		ft_printf("-");
}

void	other_rights(struct stat rights)
{
	if ((rights.st_mode & S_IWOTH) == 2)
		ft_printf("w");
	else
		ft_printf("-");
	if ((rights.st_mode & S_ISVTX) != 0 && (rights.st_mode & S_IXOTH) == 1)
		ft_printf("t  ");
	else if ((rights.st_mode & S_ISVTX) != 0)
		ft_printf("T  ");
	else if ((rights.st_mode & S_IXOTH) == 1)
		ft_printf("x  ");
	else
		ft_printf("-  ");
}

void	group_rights(struct stat rights)
{
	if ((rights.st_mode & S_IRGRP) == 32)
		ft_printf("r");
	else
		ft_printf("-");
	if ((rights.st_mode & S_IWGRP) == 16)
		ft_printf("w");
	else
		ft_printf("-");
	if ((rights.st_mode & S_ISGID) != 0 && (rights.st_mode & S_IXGRP) == 8)
		ft_printf("s");
	else if ((rights.st_mode & S_ISGID) != 0)
		ft_printf("S");
	else if ((rights.st_mode & S_IXGRP) == 8)
		ft_printf("x");
	else
		ft_printf("-");
	if ((rights.st_mode & S_IROTH) == 4)
		ft_printf("r");
	else
		ft_printf("-");
	other_rights(rights);
}

int		aff_rights(char *str, int i, t_command *command_list, int g)
{
	struct stat rights;
	char		*path;
	char		*name;

	lstat(str, &rights);
	aff_type(rights.st_mode);
	if ((rights.st_mode & S_IRUSR) == 256)
		ft_printf("r");
	else
		ft_printf("-");
	if ((rights.st_mode & S_IWUSR) == 128)
		ft_printf("w");
	else
		ft_printf("-");
	if ((rights.st_mode & S_ISUID) != 0 && (rights.st_mode & S_IXUSR) == 64)
		ft_printf("s");
	else if ((rights.st_mode & S_ISUID) != 0)
		ft_printf("S");
	else if ((rights.st_mode & S_IXUSR) == 64)
		ft_printf("x");
	else
		ft_printf("-");
	group_rights(rights);
	aff_users(rights, i, command_list, g);
	return (1);
}
