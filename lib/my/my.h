/*
** EPITECH PROJECT, 2017
** File Name : my.h
** File description:
** By Arthur Teisseire
*/

#ifndef MY_H
#define MY_H

#include <unistd.h>

void my_putchar(char c);
void my_puterror(char *str);
void my_putstr(char *str);
int my_strlen(char *str);
int my_atoi(char *str);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
int count_words(char *str, char *flags);
char *get_next_word(char **str, char *flags);
int in_str(char c, char *str);
int len_first_word(char *str, char *flags);
char *my_strncpy(char *dest, char const *src, int n);
int skip_first_flags(char **str, char *flags);
char **split(char *str, char *flags);

#endif
