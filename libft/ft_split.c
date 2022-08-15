/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 01:05:20 by gpiccion          #+#    #+#             */
/*   Updated: 2022/02/12 01:05:20 by gpiccion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns the length of a word delimited by the character 'c'.
static size_t	ft_word_length(const char *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

// Counts the amount of words delimited by 'c' in the array 's'.
static size_t	ft_countwords(const char *s, char c)
{
	size_t	wcount;
	size_t	i;

	i = 0;
	wcount = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			wcount++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (wcount);
}

// Liberates memory of the array pointed by 's'.
static char	*ft_freearray(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		free(&s[i]);
		i++;
	}
	return (NULL);
}

// Allocates a word delimited by 'c', and returns a pointer to it.
static char	*ft_walloc(char *out, const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] == c)
		i++;
	out = malloc(ft_word_length(s, c) + 1);
	if (!out)
		return (ft_freearray(out));
	while (s[i] != c && s[i])
	{
		out[i] = s[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

// Allocates and returns an array of strings obtained by splitting 's'
// using the character 'c' as a delimiter.
// The array must be ended by a NULL pointer.
// Returns NULL if the allocation fails. 
char	**ft_split(char const *s, char c)
{
	size_t	wcount;
	size_t	i;
	char	**out;

	if (!s)
		return (NULL);
	wcount = ft_countwords(s, c);
	out = (char **)malloc(sizeof(char *) * (wcount + 1));
	if (!out)
		return (NULL);
	i = 0;
	while (i < wcount)
	{
		while (*s == c)
			s++;
		out[i] = ft_walloc(out[i], s, c);
		i++;
		while (*s && *s != c)
			s++;
	}
	out[i] = NULL;
	return (out);
}
