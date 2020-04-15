/*
** EPITECH PROJECT, 2019
** my swap
** File description:
** swap content of two integers
*/

#include <unistd.h>
#include <stdio.h>

void my_swap(int *a, int *b)
{
    int *c = *a;
    *a = *b;
    *b = c;
}
