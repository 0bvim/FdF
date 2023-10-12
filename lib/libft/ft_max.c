/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:30:49 by vde-frei          #+#    #+#             */
/*   Updated: 2023/10/12 11:31:54 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

signed int	ft_max(signed int valA, signed int valB)
{
	return (valA * (valA >= valB) + valB * (valB > valA));
}
