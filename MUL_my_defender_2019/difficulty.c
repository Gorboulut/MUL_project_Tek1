/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** difficulty selection for defender
*/
#include "include/my_defender.h"

diff_t *list_diff(game_t *game, char *text, int diff, char *text_map)
{
    diff_t *new = malloc(sizeof(diff_t));
    diff_t *tmp;

    new->diff = diff;
    new->sprite = sfSprite_create();
    new->texture = sfTexture_createFromFile(text, NULL);
    new->text_map = sfTexture_createFromFile(text_map, NULL);
    new->spr_map = sfSprite_create();
    new->pos.x = 650;
    new->pos.y = 380;
    new->next = NULL;
    new->prev = NULL;
    if (!game->diff)
        return (new);
    tmp = game->diff;
    while (tmp->next != NULL) {
        tmp->next->prev = tmp;
        tmp = tmp->next;
    } tmp->next = new;
    return (game->diff);
}

diff_t *list_circ(game_t *game)
{
    diff_t *new = game->diff;

    new->next->prev = new;
    while (new->next != NULL) {
        new->next->prev = new;
        new = new->next;
    }
    new->next = game->diff;
    new->next->prev = new;
    return (new);
}

void check_difficulty(game_t *game)
{
    game->diff = NULL;
    game->diff = list_diff(game, "src/easy.jpg", 1, "src/map_normal.jpg");
    game->diff = list_diff(game, "src/medium.jpg", 2, "src/map_middle.jpg");
    game->diff = list_diff(game, "src/hard.jpg", 3, "src/map_hard.jpg");
    game->diff = list_circ(game);
    game->diff = game->diff->next;
}
