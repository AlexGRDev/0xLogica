/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexgarc4 <alexgarc4@student.42barcelon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:48:49 by alexgarc4         #+#    #+#             */
/*   Updated: 2025/06/19 11:00:00 by alexgarc4        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (n);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	else if (n >= 10)
		putnbr(n / 10);
	n = (n % 10) + '0';
	return (write(1, &n, 1));
}

int	fizzbuzz(int **n)
{
	if (**n % 3 == 0 && **n % 5 == 0)
	{
		write(1, "fizzbuzz\n", 9);
	}
	else if (**n % 3 == 0)
	{
		write(1, "fizz\n", 5);
	}
	else if (**n % 5 == 0)
	{
		write(1, "buzz\n", 5);
	}
	else
	{
		putnbr(**n);
		write(1, "\n", 1);
	}
	return (putnbr(**n));
}

int	main(void)
{
	int	*n;

	n = malloc(sizeof(int));
	if (n == 0)
		write(1, "Memory can't be assigned\n", 25);
	*n = 1;
	while (*n < 100)
	{
		fizzbuzz(&n);
		(*n)++;
	}
	free (n);
	return (0);
}
