/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** find the first occurrence of a string
*/
#include <stdio.h>

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int x = 0;
    int y = 0;
    char rep[100];

    while (str[i] != '\0') {
        while (to_find[y] == str[i]) {
            rep[x] = str[i];
            x++;
            i++;
            y++;
        }
        i++;
    }
    return (rep);
}
