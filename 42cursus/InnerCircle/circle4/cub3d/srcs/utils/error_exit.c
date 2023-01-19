/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:53:35 by doykim            #+#    #+#             */
/*   Updated: 2023/01/19 20:11:00 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_exit(int n)
{
	if (n == 1)
		printf("argument error");
	else if (n == 2)
		printf("element error");
	else if (n == 3)
		printf("map error");
	exit(1);
}
