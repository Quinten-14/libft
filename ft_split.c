/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:24:23 by qraymaek          #+#    #+#             */
/*   Updated: 2023/10/15 20:10:44 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_count_words(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	if (s[0] != c)
		count++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			count++;
		i++;
	}
	return (count);
}

static int	ft_word_len(char const *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static char	**ft_free(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!tab || !s)
		return (NULL);
	while (i < ft_count_words(s, c))
	{
		while (s[j] == c)
			j++;
		if (!s[j])
			break ;
		tab[i] = ft_substr(s, j, ft_word_len(&s[j], c));
		if (!tab[i])
			return (ft_free(tab, i));
		j += ft_word_len(&s[j], c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
