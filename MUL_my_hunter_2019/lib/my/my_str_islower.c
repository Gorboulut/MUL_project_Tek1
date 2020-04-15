/*
** EPITECH PROJECT, 2019
** my str lower
** File description:
** return 1 if the string contains only alpha char
*/

int my_str_islower(char const *str)
{
    int i = 0;
    while (str[i] > 96 && str[i] < 123) {
        if (str[i + 1] == '\0')
            return (1);
        i++;
    }
    return (0);
}
