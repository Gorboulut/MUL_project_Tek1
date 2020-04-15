/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** recreate a tower defense type game
*/
#include "include/my_defender.h"

void call_menu(game_t *game)
{
    sfSprite_setTexture(game->win->sprite, game->win->texture, 1);
    sfRenderWindow_drawSprite(game->window, game->win->sprite, NULL);
}

void call_loose(game_t *game)
{
    sfSprite_setTexture(game->loose->sprite, game->loose->texture, 1);
    sfRenderWindow_drawSprite(game->window, game->loose->sprite, NULL);
}

void condition_lose_win(game_t *game)
{
    if (game->lose == game->nb_enemy - 3) {
        game->nb_enemy += 1;
        game->menu = 7;
    }
    if (game->nb_wave == 5)
        game->menu = 8;
}

void call_play(game_t *game)
{
    enemy_t *enemy = game->enemy;
    enemy_t *def = game->tmp;

    condition_lose_win(game);
    sfSprite_setTexture(game->diff->spr_map, game->diff->text_map, 1);
    sfRenderWindow_drawSprite(game->window, game->diff->spr_map, NULL);
    while (def) {
        sfSprite_setTexture(def->sprite2, def->texture2, sfTrue);
        sfSprite_setTexture(def->sprite, def->texture, sfTrue);
        sfSprite_setTextureRect(def->sprite2, def->rect);
        sfRenderWindow_drawSprite(game->window, def->sprite2, NULL);
        sfRenderWindow_drawSprite(game->window, def->sprite, NULL);
        def = def->next;
    }
    while (enemy) {
        sfSprite_setPosition(enemy->sprite, enemy->pos);
        sfRenderWindow_drawSprite(game->window, enemy->sprite, NULL);
        enemy = enemy->next;
    }
    sfRenderWindow_drawText(game->window, game->text->text, NULL);
}

void make_lose(game_t *game)
{
    sfSprite_setTexture(game->loose->sprite, game->loose->texture, 1);
    sfRenderWindow_drawSprite(game->window, game->loose->sprite, NULL);
}