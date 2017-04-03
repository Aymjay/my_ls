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

char		*add_name(char *str, char *src)
{
	char	*cpy;
	int		i;
	int		g;

	i = 0;
	g = 0;
	if (!str)
		return (src);
	cpy = malloc((ft_strlen(str) + ft_strlen(src) + 2) * sizeof(char));
	while (str[i])
	{
		cpy[i] = str[i];
		++i;
	}
	if (str[i - 1] != '/')
		cpy[i++] = '/';
	while (src[g])
		cpy[i++] = src[g++];
	cpy[i++] = '\0';
	return (cpy);
}

t_file		*new_file(char *str)
{
	t_file *new_file;

	new_file = malloc(sizeof(t_file));
	new_file->name = ft_strdup(str);
	new_file->next = NULL;
	return (new_file);
}

void		add_file(t_file **file, char *str)
{
	t_file *tmp;

	tmp = *file;
	if (!(*file)->name)
	{
		free(*file);
		tmp = new_file(str);
		*file = tmp;
		return ;
	}
		else while (tmp->next)
			tmp = tmp->next;
	tmp->next = new_file(str);
}

void		check_stop_command(char *str, int *stop)
{
	if (*stop == 1)
		return ;
	if (ft_strcmp(str, "--") == 0 || str[0] != '-')
		*stop = 1;
}

void		to_file(char **tab, t_file **file)
{
	int g;
	int stop;

	stop = 0;
	g = 1;
	*file = malloc(sizeof(t_file));
	(*file)->name = NULL;
	(*file)->next = NULL;
	while (tab[g])
	{
		if (ft_strcmp(tab[g], "-") == 0)
			stop = 1;
		if (tab[g][0] != '-' || stop == 1)
			add_file(file, tab[g]);
		check_stop_command(tab[g], &stop);
		++g;
	}
}
