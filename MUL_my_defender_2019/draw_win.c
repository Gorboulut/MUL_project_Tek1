/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** draw_win.c
*/

#include "include/my_defender.h"

void make_win(game_t *game)
{
    sfSprite_setTexture(game->print_win->sprite, game->print_win->texture, 1);
    sfRenderWindow_drawSprite(game->window, game->print_win->sprite, NULL);
}