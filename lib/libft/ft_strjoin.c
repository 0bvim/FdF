/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:06:02 by vde-frei          #+#    #+#             */
/*   Updated: 2023/08/01 18:02:31 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	mark;
	size_t	count;
	char	*new_str;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	mark = 0;
	count = 0;
	new_str = (char *)ft_calloc(len, sizeof(char));
	if (!new_str)
		return (NULL);
	while (s1[mark] != '\0')
	{
		new_str[mark++] = s1[count++];
	}
	count = 0;
	while (s2[count] != '\0' && ft_strlen(s2))
	{
		new_str[mark++] = s2[count++];
	}
	return (new_str);
}
