/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 17:02:25 by itopchu       #+#    #+#                 */
/*   Updated: 2022/10/08 17:02:25 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

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

void	ft_putnbr_fd(int n, int fd)
{
	char	*str;

	if (fd < 0)
		return ;
	str = ft_itoa(n);
	if (!str)
		return ;
	write(fd, str, ft_strlen(str));
	free(str);
}
