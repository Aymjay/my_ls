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

void	display_help_menu(void)
{
	ft_printf("\t {green}{u}COMMAND LIST{eoc} {green}:{eoc}\n");
	ft_printf("-h : display command list\n");
	ft_printf("-1 : 1 column display\n");
	ft_printf("-a : display hidden files\n");
	ft_printf("-l : display files & more informations\n");
	ft_printf("-t : sort by time\n");
	ft_printf("-r : revert the sort\n");
	ft_printf("-A : display hidden files without . & ..\n");
	ft_printf("-c : add colors\n");
	ft_printf("-s : display size	\n");
	ft_printf("-i : display index\n");
	ft_printf("-o : don't list group\n");
	ft_printf("-g : don't list owner\n");
	exit(0);
}
