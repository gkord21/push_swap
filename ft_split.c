/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:46:21 by gkord             #+#    #+#             */
/*   Updated: 2022/03/11 15:03:48 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_num_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			while (s[i] != c && s[i])
				i++;
			count++;
		}
	}
	return (count);
}

static size_t	ft_strlen_mod(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**ft_error_free(char **res)
{
	size_t	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	ft_error_exit();
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*sub_s;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	sub_s = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub_s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			sub_s[j] = s[i];
			j++;
		}
		i++;
	}
	sub_s[j] = '\0';
	return (sub_s);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	index_w;

	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (ft_num_words(s, c) + 1));
	if (!res)
		return (NULL);
	i = 0;
	index_w = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			res[index_w] = ft_substr(s, i, ft_strlen_mod(s + i, c));
			if (!res)
				return (ft_error_free(res));
			i = i - 1 + ft_strlen_mod(s + i, c);
			index_w++;
		}
		i++;
	}
	res[index_w] = NULL;
	return (res);
}
