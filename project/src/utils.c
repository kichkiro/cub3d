/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 11:09:31 by kichkiro          #+#    #+#             */
/*   Updated: 2023/06/30 18:21:02 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_fatal(char *msg)
{
	ft_putstr_fd(RED_B, 2);
	ft_putstr_fd("Error\n", 2);
	perror(msg);
	ft_putstr_fd(RESET, 2);

	// free all

	exit(1);
}
