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

int		read_a_dir(DIR *file)
{
	struct dirent *tmp;

	tmp = readdir(file);
	while (tmp)
	{
		if (tmp->d_name[0] != '.')
			ft_printf("%s\n", tmp->d_name);
		tmp = readdir(file);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int i;
	DIR *tmp;

	i = 1;
	to_parsing(argv);
	return (1);
}
