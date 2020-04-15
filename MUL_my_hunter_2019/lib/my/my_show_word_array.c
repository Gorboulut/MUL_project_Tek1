/*
** EPITECH PROJECT, 2019
** my show word array
** File description:
** display all word of a tab, one per line
*/
#include <stdio.h>
#include <stdlib.h>

int my_show_word_array(char * const *tab)
{
    int i = 0;
    int x = 0;
    int length = 0;
    char *str;

    for (x = 0; tab[x] != '\0'; x++);
    while (i < x) {
        length = length + my_strlen(tab[i]);
        i++;
    }
    str = malloc(sizeof(char) + length + 1);
    i = 0;
    while (i < x) {
        my_putstr(tab[i]);
        my_putchar('\n');
        i++;
    }
    return (0);
}
