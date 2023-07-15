/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 17:00:51 by itopchu       #+#    #+#                 */
/*   Updated: 2022/10/08 17:00:51 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

#include <stdlib.h>

static int	len_in(int n)
{
	int	ret;

	if (!n)
		return (1);
	ret = 1;
	while (n != 0)
	{
		n /= 10;
		ret++;
	}
	return (ret);
}

static char	*fill(char *ret, int n, int len)
{
	if (!n)
	{
		ret[0] = '0';
		return (ret);
	}
	while (n)
	{
		ret[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	char		*ret;
	int			len;
	int			sign;

	len = len_in(n);
	if (n < 0)
		len++;
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	sign = 1;
	if (n < 0)
		ret[0] = '-';
	return (fill(ret, n, len - 1));
}
