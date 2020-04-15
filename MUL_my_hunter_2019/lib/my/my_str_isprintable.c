/*
** EPITECH PROJECT, 2019
** my str is printable
** File description:
** return 1 if only contain printable char
*/

int my_str_isprintable(char const *str)
{
    int i = 0;
    while (str[i] > 32 && str[i] < 127) {
        if (str[i + 1] == '\0')
            return (1);
        i++;
    }
    return (0);
}
