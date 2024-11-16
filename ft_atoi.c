/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:25:32 by wimam             #+#    #+#             */
/*   Updated: 2024/11/15 16:12:41 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_skip(const char *str, const char ret)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (ret == 'i')
		return (i);
	else if (ret == 's')
		return (sign);
	return (0);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long			result;
	unsigned long	tmp_result;

	i = ft_skip(str, 'i');
	sign = ft_skip(str, 's');
	result = 0;
	tmp_result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		tmp_result = ((tmp_result * 10 + (str[i] - '0')));
		if (tmp_result >= L_MAX && sign == 1)
			return (-1);
		if (tmp_result >= L_MIN && sign == -1)
			return (0);
		i++;
	}
	return (result * sign);
}
