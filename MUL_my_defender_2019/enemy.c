/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** enemy.c
*/

#include "include/my_defender.h"

enemy_t *push_enemy(game_t *game, char *image)
{
    enemy_t *new = malloc(sizeof(enemy_t));
    enemy_t *tmp;

    new->sprite = sfSprite_create();
    new->texture = sfTexture_createFromFile(image, NULL);
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    new->next = NULL;
    if (!game->enemy)
        return (new);
    tmp = game->enemy;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new;
    return (game->enemy);
}

void position_enemy(game_t *game)
{
    enemy_t *enemy = game->enemy;

    while (enemy) {
        enemy->pos.x = -700 + rand() % 300;
        enemy->pos.y = rand() % 880;
        enemy = enemy->next;
    }
}

void create_enemy(game_t *game)
{
    game->bool = 1;
    for (int j = 0; j != game->nb_enemy; j++)
        game->enemy = push_enemy(game, "src/avion.png");
    position_enemy(game);
}
