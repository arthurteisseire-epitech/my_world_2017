/*
** EPITECH PROJECT, 2017
** File Name : itoa.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>

int nb_len(int nb)
{
	int len = 0;

	while (nb > 0) {
		nb /= 10;
		len++;
	}
	return (len);
}

int my_pow(int nb, int power)
{
	int res = 1;

	if (power == 0)
		return (1);
	while (power > 0) {
		res *= nb;
		power--;
	}
	return (res);
}

char *my_itoa(int nb)
{
	int len = nb_len(nb);
	char *res = malloc(sizeof(char) * (len + 1));
	int i = 0;
	int power;

	res[len] = '\0';
	while (len > 0) {
		power = my_pow(10, len - 1);
		res[i] = nb / power;
		nb -= res[i] * power;
		res[i] += '0';
		len--;
		i++;
	}
	return (res);
}
