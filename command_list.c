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

t_command		*new_command(char c)
{
	t_command *new_command;

	new_command = malloc(sizeof(t_command));
	new_command->letter = c;
	new_command->next = NULL;
	return (new_command);
}

void			add_command(t_command **command_list, char c)
{
	t_command *tmp;

	tmp = *command_list;
	if (!tmp)
	{
		tmp = new_command(c);
		*command_list = tmp;
		return ;
	}
		else while (tmp->next)
			tmp = tmp->next;
	tmp->next = new_command(c);
}

void			to_command(char **tab, t_command **command_list)
{
	int g;
	int h;

	if (!tab[1])
		return ;
	g = 1;
	h = 1;
	while (tab[g])
	{
		if (tab[g][0] == '-' && !tab[g][1])
			return ;
		while (tab[g][0] == '-' && tab[g][h])
		{
			if (tab[g][1] == '-' && !tab[g][2])
				return ;
			add_command(command_list, tab[g][h]);
			++h;
		}
		if (tab[g][0] != '-')
			return ;
		h = 1;
		++g;
	}
}
