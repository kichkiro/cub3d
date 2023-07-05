/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:17:46 by anvannin          #+#    #+#             */
/*   Updated: 2023/07/05 20:35:27 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	error_message(char *msg_type)
{
	if (!ft_strncmp(msg_type, "usage", 6))
		printf("%susage: ./minirt <path_scene>.rt%s\n", YELLOW, RESET);
	else
		printf("%sError%s\n", RED, RESET);
	return (1);
}
