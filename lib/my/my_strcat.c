/*
** EPITECH PROJECT, 2017
** File Name : my_strcat.c
** File description:
** By Arthur Teisseire
*/

char *my_strcat(char *dest, char const *src)
{
	int i = 0;

	while (dest[i] != '\0')
		i++;
	for (int j = 0; src[j] != '\0'; j++) {
		dest[i] = src[j];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
