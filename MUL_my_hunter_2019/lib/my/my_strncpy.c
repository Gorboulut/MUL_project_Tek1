/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** function that copie n characters into another
*/
#include <stdio.h>
#include <string.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    if (n == 0)
        return (dest = "");
    while (i < n) {
        dest[i] = src[i];
        i++;
    }
    if (i <= n)
        dest[i] = '\0';
    return (dest);
}
