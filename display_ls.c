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

void	display_everywhere_sncd(t_command *command_list, t_file *file_list,\
		t_directory *directory, t_directory **begin)
{
	t_directory *cpy;

	if (check(command_list, 'R') == 1)
	{
		while (directory)
		{
			if (can_we_open_rec(directory->d_name, command_list) == 1\
			&& is_directory(directory->d_name, file_list->name) == 1)
			{
				ft_printf("\n");
				aff_with_directory(command_list,\
				directory->d_name, file_list->name, NULL);
			}
			cpy = directory;
			directory = directory->next;
			free(cpy->d_name);
			free(cpy);
		}
	}
	else
		erraz_directory(begin);
}

int		display_everywhere(t_command *command_list, t_file *file_list)
{
	t_directory *directory;
	DIR			*tmp;
	t_directory **begin;

	if (!file_list)
		return (1);
	tmp = opendir(file_list->name);
	if (!tmp)
		perror("Error");
	else
	{
		directory = dirent_cpy(tmp);
		sort_directory(command_list, &directory);
		ft_printf("%s:\n", file_list->name);
		read_a_dir_lol(directory, command_list, file_list->name);
		closedir(tmp);
		begin = &directory;
		display_everywhere_sncd(command_list, file_list, directory, begin);
	}
	file_list = file_list->next;
	if (file_list)
		ft_printf("\n");
	return (display_everywhere(command_list, file_list));
}

void	display_here_scnd(t_command *command_list, t_directory *directory)
{
	t_directory *cpy;

	while (directory)
	{
		if (can_we_open_rec(directory->d_name, command_list) == 1\
		&& is_directory(directory->d_name, ".") == 1)
		{
			ft_printf("\n");
			aff_with_directory(command_list, directory->d_name, ".", NULL);
		}
		directory = directory->next;
	}
}

int		display_here(t_command *command_list)
{
	DIR			*tmp;
	t_directory *directory;
	t_directory **begin;

	tmp = opendir(".");
	directory = dirent_cpy(tmp);
	sort_directory(command_list, &directory);
	if (check(command_list, 'R') == 1)
		ft_printf(".:\n");
	read_a_dir_lol(directory, command_list, ".");
	begin = &directory;
	if (check(command_list, 'R') == 1)
		display_here_scnd(command_list, directory);
	erraz_directory(begin);
	closedir(tmp);
	return (1);
}

int		just_display(t_file *file_list)
{
	DIR			*tmp;
	t_directory *directory;

	while (file_list)
	{
		tmp = opendir(file_list->name);
		if (!tmp)
			perror("Error");
		else
		{
			ft_printf("%s:\n", file_list->name);
			directory = dirent_cpy(tmp);
			sort_by_alpha(directory, &directory);
			read_a_dir_lol(directory, NULL, file_list->name);
			closedir(tmp);
			if (file_list->next)
				ft_printf("\n");
			erraz_directory(&directory);
		}
		file_list = file_list->next;
	}
	return (1);
}
