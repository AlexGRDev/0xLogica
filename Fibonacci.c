/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fibonacci.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexgarc4 <alexgarc4@student.42barcelon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 08:16:26 by alexgarc4         #+#    #+#             */
/*   Updated: 2025/06/20 10:09:50 by alexgarc4        ###   ########.fr       */
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

int	fibonacci(int *n)
{
	int	val1;
	int	val2;

	val1 = *n -1;
	val2 = *n -2;
	if (*n < 0)
		return (0);
	if (*n == 0)
		return (0);
	if (*n == 1)
		return (1);
	return (fibonacci(&val1) + fibonacci(&val2));
}

int	main(void)
{
	int	*n;
	int	result;

	n = malloc(sizeof(int));
	if (n == 0)
	{
		write(1, "Memory can't be assigned\n", 25);
	}
	*n = 0;
	while (*n < 100)
	{
		result = fibonacci(n);
		putnbr(result);
		write(1, "\n", 1);
		(*n)++;
	}
	free(n);
	return (0);
}
