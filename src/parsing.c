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

void	erraz_command(t_command **command_list)
{
	t_command *cpy;

	while (*command_list)
	{
		cpy = (*command_list)->next;
		free(*command_list);
		*command_list = cpy;
	}
}

void	erraz_file(t_file **file_list)
{
	t_file *cpy;

	while (*file_list)
	{
		cpy = (*file_list)->next;
		free((*file_list)->name);
		free(*file_list);
		*file_list = cpy;
	}
}

int		check_letter(char c)
{
	if (c == 'A' || c == 'a' || c == 's' || c == 'i')
		return (1);
	if (c == 'c' || c == 't' || c == 'R' || c == 'r')
		return (1);
	if (c == 'l' || c == '1' || c == 'o' || c == 'g')
		return (1);
	if (c == 'h')
		return (1);
	return (0);
}

int		check_invalid_command(t_command *command_list)
{
	while (command_list)
	{
		if (check_letter(command_list->letter) == 1)
			command_list = command_list->next;
		else
			return (0);
	}
	return (1);
}

int		to_parsing(char **tab)
{
	t_command	*command_list;
	t_file		*file_list;
	t_file		**aff;

	command_list = NULL;
	to_command(tab, &command_list);
	if (check(command_list, 'h') == 1)
		display_help_menu();
	to_file(tab, &file_list);
	if (file_list && file_list->name)
	{
		sort_by_alpha_file(file_list, &file_list);
		if (check(command_list, 'r') == 1)
			reverse_sort_file(&file_list);
		sort_by_type(file_list, &file_list);
	}
	if (check_invalid_command(command_list) == 0)
		ft_printf("Bad option\n");
	else
		ft_ls(command_list, file_list);
	erraz_command(&command_list);
	erraz_file(&file_list);
	return (1);
}
