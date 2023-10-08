/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:18:58 by vde-frei          #+#    #+#             */
/*   Updated: 2023/10/06 06:51:11 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		nb;
	int		sign;
	char	*string;

	sign = 1;
	string = (char *)nptr;
	while ((*string >= 9 && *string <= 13) || *string == 32)
		string++;
	while (*string == '-' || *string == '+')
	{
		if (*(string + 1) == '-' || *(string + 1) == '+')
			return (0);
		if (*string == '-')
			sign = -1;
		string++;
	}
	nb = 0;
	while (*string >= '0' && *string <= '9')
	{
		nb *= 10;
		nb += *string - 48;
		string++;
	}
	return (nb *= sign);
}
