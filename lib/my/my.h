/*
** EPITECH PROJECT, 2017
** File Name : my.h
** File description:
** By Arthur Teisseire
*/

#ifndef MY_H
#define MY_H

#ifndef READ_SIZE
#	define READ_SIZE 4096
#endif

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
char *get_next_line(int fd);
char *my_realloc(char *dest, char *src, int len_src);
int my_strlen(char *str);
int find_backspace(char *str);
char *cut_line(char **begin, char *line, int size);
int nb_len(int nb);
int my_pow(int nb, int power);
char *my_itoa(int nb);

#endif
