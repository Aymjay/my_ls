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

void	erraz_directory(t_directory **directory)
{
	t_directory *cpy;

	while (*directory)
	{
		cpy = (*directory)->next;
		free((*directory)->d_name);
		free(*directory);
		*directory = cpy;
	}
}

void	sort_directory(t_command *command_list, t_directory **directory)
{
	if (check(command_list, 't') == 1)
		sort_by_time(*directory, directory);
	else
		sort_by_alpha(*directory, directory);
	if (check(command_list, 'r') == 1)
		reverse_sort(directory);
}

int		display_simple(char *str, t_command *command_list)
{
	other_command(str, command_list, 1);
	if ((check(command_list, 'l') + check(command_list, 'o')\
		+ check(command_list, 'g')) > 0)
		aff_rights(str, 1, command_list, 1);
	ft_printf("%s\n", str);
	return (1);
}

int		display_simple_file(t_file **file_list, t_command *command_list, int i)
{
	struct stat tmp;

	if (!*file_list || !(*file_list)->name)
		return (0);
	errno = 0;
	stat((*file_list)->name, &tmp);
	if (errno != 0)
	{
		ft_printf("ft_ls: %s : ", (*file_list)->name);
		perror(NULL);
		*file_list = (*file_list)->next;
		return (display_simple_file(file_list, command_list, ++i));
	}
	if (S_ISDIR(tmp.st_mode) == 0)
	{
		display_simple((*file_list)->name, command_list);
		*file_list = (*file_list)->next;
		return (display_simple_file(file_list, command_list, ++i));
	}
	else
		return (i);
}

int		ft_ls(t_command *command_list, t_file *file_list)
{
	struct stat tmp;
	t_file		*begin;

	begin = file_list;
	if (!file_list || !file_list->name)
		return (display_here(command_list));
	if (display_simple_file(&file_list, command_list, 0) != 0)
		ft_printf("\n");
	if (!command_list)
		just_display(file_list);
	else
		display_everywhere(command_list, file_list);
	file_list = begin;
	return (1);
}
