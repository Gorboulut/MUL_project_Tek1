/*
** EPITECH PROJECT, 2019
** concat params
** File description:
** return the command line into a single string
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat_params(int argc, char **argv)
{
    int i = 0;
    int length = 0;
    char *str;

    while (i < argc) {
        length = length + my_strlen(argv[i]);
        i++;
    }
    str = malloc(sizeof(char) + length + 1);
    i = 0;
    while (i < argc) {
        my_strcat(str, argv[i]);
        my_strcat(str, "\n");
        i++;
    }
    str[length + i - 1] = '\0';
    return (str);
}
