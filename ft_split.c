/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:15:17 by wimam             #+#    #+#             */
/*   Updated: 2024/11/10 09:47:22 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_row(char const *s, char c)
{
	int		ret;

	ret = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			ret++;
		while (*s && *s != c)
			s++;
	}
	return (ret);
}

static char	*ft_fill(char const *s, char c)
{
	int		len;
	char	*buffer;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	buffer = malloc(len + 1);
	if (!buffer)
		return (NULL);
	ft_memcpy(buffer, s, len);
	buffer[len] = '\0';
	return (buffer);
}

char	**ft_split(char const *s, char c)
{
	char	**buffer;
	int		row;
	int		i;

	if (!s)
		return (NULL);
	row = ft_row(s, c);
	buffer = malloc((row + 1) * sizeof(char *));
	if (!buffer)
		return (NULL);
	i = 0;
	while (i < row)
	{
		while (*s && *s == c)
			s++;
		buffer[i++] = ft_fill(s, c);
		while (*s && *s != c)
			s++;
	}
	buffer[row] = NULL;
	return (buffer);
}
