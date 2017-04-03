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

void	other_command(char *str, t_command *command_list, int block_max)
{
	struct stat tmp;
	long		i;

	lstat(str, &tmp);
	if (check(command_list, 'i') == 1)
		ft_printf("%llu ", tmp.st_ino);
	if (check(command_list, 's') == 1)
	{
		i = tmp.st_blocks / 2;
		aff_size(i, block_max);
	}
}

int		can_we_open(char *str, t_command *command_list)
{
	if (str[0] != '.')
		return (1);
	if (str[0] == '.' && check(command_list, 'a') == 1)
		return (1);
	if (ft_strcmp(".", str) != 0 && ft_strcmp("..", str) != 0\
		&& check(command_list, 'A') == 1)
		return (1);
	return (0);
}
