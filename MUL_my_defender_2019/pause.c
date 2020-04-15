/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** pause.c
*/

#include "include/my_defender.h"

void make_pause(game_t *game)
{
    sfSprite_setTexture(game->pause->sprite, game->pause->texture, sfTrue);
    sfRenderWindow_drawSprite(game->window, game->pause->sprite, NULL);
}

void pause_click(game_t *game, sfVector2i c)
{
    enemy_t *enemy = game->enemy;
    enemy_t *def = game->tmp;

    if (c.x > 670 && c.x < 1035 && c.y < 620 && c.y > 560 && game->menu == 6)
        game->menu = 2;
    if (c.x > 680 && c.x < 1010 && c.y < 695 && c.y > 645 && game->menu == 6) {
        while (enemy) {
            enemy->pos.x = -700 + rand() % 300;
            enemy = enemy->next;
        }
        game->tmp = NULL;
        game->menu = 0;
    }
    if (c.x > 680 && c.x < 830 && c.y < 785 && c.y > 735 && game->menu == 6)
        sfRenderWindow_close(game->window);
}