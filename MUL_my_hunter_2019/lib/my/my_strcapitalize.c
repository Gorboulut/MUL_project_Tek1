/*
** EPITECH PROJECT, 2019
** my_strcapitalize
** File description:
** capitalize the first letter of every word
*/
#include <stdio.h>

char *my_strcapitalize(char *str)
{
    int i = 1;

    my_strlowlowcase(str);
    if (str[0] < 123 && str[0] > 96)
        str[0] = str[0] - 32;
    while (str[i] != '\0') {
        while (str[i + 1] > 47 && str[i + 1] < 58)
            i++;
        if (str[i] == ' ' || str[i] == '-' || str[i] == ';' || str[i] == '+') {
            str[i + 1] = str[i + 1] - 32;
        }
        i++;
    }
    return (str);
}
