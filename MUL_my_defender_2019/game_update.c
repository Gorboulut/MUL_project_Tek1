/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** game_update.c
*/

#include "include/my_defender.h"

void check_enemy_position(game_t *game, enemy_t *enemy, enemy_t *def)
{
    while (enemy) {
        if ((enemy->pos.x + 100 > def->pos_aura.x + 20) &&
            (enemy->pos.y + 124 > def->pos_aura.y - 110) &&
            (enemy->pos.y < def->pos_aura.y + 110) &&
            (enemy->pos.y > def->pos_aura.y) &&
            (enemy->pos.x < def->pos_aura.x + 200)) {
            def->rect.left = 710;
            sfSprite_setTextureRect(def->sprite2, def->rect);
            game->money += 5;
            game->kill++;
            enemy->pos.x = 3000;
        }
        enemy = enemy->next;
    }
}

void enemy_move(game_t *game, float elapsed)
{
    enemy_t *enemy = game->enemy;

    game->lose = 0;
    while (enemy) {
        enemy->pos.x += (200 * game->diff->diff * game->speed) * elapsed;
        if (enemy->pos.x > 1700 && enemy->pos.x < 2000)
            game->lose++;
        enemy = enemy->next;
    }
}

void wave(game_t *game)
{
    if ((game->lose + game->kill == game->nb_enemy)) {
        game->lose = 0;
        game->kill = 0;
        game->tmp = NULL;
        game->nb_wave++;
        game->nb_enemy++;
        game->speed += 0.2;
        create_enemy(game);
    }
}

void game_update(game_t *game, float elapsed)
{
    if (game->lose != game->nb_enemy && game->bool == 0)
        create_enemy(game);
    enemy_t *enemy = game->enemy;
    enemy_t *def = game->tmp;

    game->time += elapsed;
    if (enemy && game->menu == 2) {
        enemy_move(game, elapsed);
        while (def) {
            enemy = game->enemy;
            check_enemy_position(game, enemy, def);
            def = def->next;
        }
    }
    wave(game);
}