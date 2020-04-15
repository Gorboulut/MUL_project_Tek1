/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** game_render.c
*/

#include "include/my_defender.h"

void game_render(game_t *game)
{
    get_menu(game);
    sfRenderWindow_display(game->window);
}
