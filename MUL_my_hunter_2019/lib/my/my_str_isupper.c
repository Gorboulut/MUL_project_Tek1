/*
** EPITECH PROJECT, 2019
** my str isupper
** File description:
** return 1 if the string contain only uppercase alpha
*/

int my_str_isupper(char const *str)
{
    int i = 0;
    while (str[i] > 64 && str[i] < 91) {
        if (str[i + 1] == '\0')
            return (1);
        i++;
    }
    return (0);
}
