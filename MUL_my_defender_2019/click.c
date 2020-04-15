/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** lose.c
*/

#include "include/my_defender.h"

void win_click(game_t *game, sfVector2i c)
{
    if (c.x > 405 && c.x < 1290 && c.y < 700 && c.y > 520 &&
        game->menu == 8) {
        game->enemy = NULL;
        game->tmp = NULL;
        game->lose = 0;
        game->nb_wave = 0;
        game->menu = 0;
        game->bool = 0;
    }
    if (c.x > 1585 && c.x < 1655 && c.y < 125 && c.y > 40 &&
        game->menu == 8)
        sfRenderWindow_close(game->window);
}

void click(game_t *game, sfVector2i c)
{
    if (c.x > 405 && c.x < 1290 && c.y < 750 && c.y > 575 &&
        game->menu == 7) {
        game->enemy = NULL;
        game->tmp = NULL;
        game->lose = 0;
        game->menu = 0;
        game->bool = 0;
    }
    if (c.x > 1585 && c.x < 1655 && c.y < 125 && c.y > 40 &&
        game->menu == 7)
        sfRenderWindow_close(game->window);
    pause_click(game, c);
    win_click(game, c);
}