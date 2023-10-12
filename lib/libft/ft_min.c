/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:32:03 by vde-frei          #+#    #+#             */
/*   Updated: 2023/10/12 11:33:01 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

signed int	ft_min(signed int valA, signed int valB)
{
	return (valA * (valA <= valB) + valB * (valB < valA));
}
