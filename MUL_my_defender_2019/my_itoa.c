/*
** EPITECH PROJECT, 2020
** lib/my
** File description:
** my_itoa.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void);

char *my_revstr(char *str)
{
    char k;
    int h;
    int j;

    h = 0;
    while (str[h] != '\0')
        h++;
    j = -1;
    while (j <= h) {
        k = str[j];
        str[j] = str[h];
        str[h] = k;
        j++;
        h--;
    }
    return (str);
}

char *my_itoa(int array)
{
    char *str = malloc(sizeof(char) *10);
    int j = 0;

    if (array == 0) {
        str[j] = 48;
        str[j + 1] = '\0';
        return (str);
    }
    while (array > 0) {
        str[j] = array % 10 + 48;
        j++;
        array /= 10;
    }
    str[j] = '\0';
    str = my_revstr(str);
    return (str);
}