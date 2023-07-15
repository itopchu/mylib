/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 17:02:59 by itopchu       #+#    #+#                 */
/*   Updated: 2022/10/08 17:02:59 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static void	ft_free_local_2m(char	**data, int word)
{
	int	i;

	if (!data)
		return ;
	i = -1;
	while (data[++i])
		free(data[i]);
	free(data);
}

static int	word_count(char const *s, char c)
{
	int	i;
	int	ret;

	ret = 0;
	i = -1;
	while (s[++i])
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			ret++;
	return (ret);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		start;
	int		word;
	char	**result;

	result = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!result)
		return (NULL);
	i = -1;
	word = 0;
	while (s[++i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			result[word] = ft_strndup(s + start, i - start);
			if (!result[word])
				return (ft_free_local_2m(result, word), NULL);
			word++;
		}
	}
	result[word] = NULL;
	return (result);
}
