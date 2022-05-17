/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ispossible.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:46:09 by doykim            #+#    #+#             */
/*   Updated: 2022/01/16 21:23:40 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern char	g_input[16];

int	ispossible_check(int i, int row, int col)
{
	if (i < 4 && row == 0 && col == i)
		return (0);
	else if (i < 8 && row == 3 && col == i - 4)
		return (0);
	else if (i < 12 && col == 0 && row == i - 8)
		return (0);
	else if (i < 16 && col == 3 && row == i - 12)
		return (0);
	return (1);
}

int	ispossible(int row, int col, int num)
{
	int	i;

	i = 0;
	while (g_input[i] != '\0')
	{
		if (g_input[i] == '3' && (num == 4 || num == 3))
		{
			if (!ispossible_check(i, row, col))
				return (0);
		}
		else if (g_input[i] == '2' && num == 4)
		{
			if (!ispossible_check(i, row, col))
				return (0);
		}
		i++;
	}
	return (1);
}
