/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexgarc4 <alexgarc4@student.42barcelon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:12:31 by alexgarc4         #+#    #+#             */
/*   Updated: 2025/06/20 12:43:29 by alexgarc4        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = '0' + (n % 10);
	write(1, &c, 1);
}

int	es_primo(int **n)
{
	int	i;

	if (**n <= 1)
		return (0);
	if (**n == 2)
		return (1);
	if (**n % 2 == 0)
		return (0);
	i = 0;
	while (i * i <= **n)
	{
		if (**n % i == 0)
		{
			write(1, &i, 1);
			write(1, "es primos\n", 10);
			return (0);
		}
		i += 2;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int	*n;
	int	is_p;

	if (argc != 2)
		return (write(1, "Usage: ./primo <number>\n", 24), 1);
	n = malloc(sizeof(int));
	if (!n)
		return (write(1, "Memory can't be assigned\n", 25), 1);
	*n = atoi(argv[1]);
	write(1, "el numero ", 10);
	ft_putnbr(*n);
	is_p = es_primo(&n);
	if (is_p)
		write(1, " es primo\n", 10);
	else
		write(1, " no es primo\n", 13);
	free(n);
	return (0);
}
