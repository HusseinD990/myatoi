/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hussein <hussein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:23:02 by hussein           #+#    #+#             */
/*   Updated: 2025/11/07 15:31:03 by hussein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	skip_delimiters(const char *s, char c, int i)
{
	while (s[i] == c)
		i++;
	return (i);
}

int	count_words(const char *s, char c)
{
	int	i;
	int	j;

	j = 0;
	i = skip_delimiters(s, c, 0);
	while (s[i])
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] != c && s[i])
				i++;
		}
		if (s[i] == c)
		{
			i = skip_delimiters(s, c , i);
		}
	}
	return (j);
}

int	len_cur_word(const char *s, char c, int j)
{
	int	i;
	
	i = 0;
	while (s[j] && s[j] != c)
	{
		j++;
		i++;
	}
	return (i);
}

void	free_all(char **strings)
{
	int	i;

	i = 0;
	while (strings[i])
	{
		free(strings[i]);
		i++;
	}
	free(strings);
}

char **ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**strings;
	
	i = -1;
	k = 0;
	strings = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!strings)
		return NULL;
	while (s[k])
	{
		if (s[k] == c || k == 0)
		{	
			if (s[k] == c && k != 0)
				strings[i][j] = '\0';
			j = 0;
			k = skip_delimiters(s, c, k);
			strings[++i] = malloc(len_cur_word(s, c, k) + 1);
			if (!strings[i])
				free_all(strings);
		}
		strings[i][j++] = s[k++];
	}
	strings[++i] = NULL;
	return (strings);
}

