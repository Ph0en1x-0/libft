/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:29:55 by wimam             #+#    #+#             */
/*   Updated: 2024/10/27 12:18:05 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		reti;

	i = 0;
	reti = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			reti = i;
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	if (reti > 0 || s[0] == (unsigned char)c)
		return ((char *)&s[reti]);
	return (NULL);
}