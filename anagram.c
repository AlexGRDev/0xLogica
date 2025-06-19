/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anagram.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexgarc4 <alexgarc4@student.42barcelon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 21:44:10 by alexgarc4         #+#    #+#             */
/*   Updated: 2025/06/19 23:45:49 by alexgarc4        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <string.h>

bool	anagram(char *str1, char *str2)
{
	int	count[256];
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (strlen(str1) != strlen(str2))
		return (false);
	while (i < 256)
	{
		count[(unsigned char)str1[i]]++;
		while (str2[j])
		{
			count[(unsigned char)str2[j]]--;
			j--;
		}
		if (count[i] != 0)
			return (true);
		i++;
	}
	return (true);
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		write(1, "Please insert two words\n", 25);
		return (1);
	}
	if (anagram(argv[1], argv[2]))
		write(1, "Son Anagramas\n", 14);
	else
		write(1, "No son Anagramas\n", 17);
	return (0);
}
