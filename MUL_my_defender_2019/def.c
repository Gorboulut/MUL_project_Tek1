/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** def.c
*/

#include "include/my_defender.h"

enemy_t *add_aura(sfVector2i c, char *aura, char *image, enemy_t *new)
{
    new->sprite = sfSprite_create();
    new->sprite2 = sfSprite_create();
    new->texture = sfTexture_createFromFile(image, NULL);
    sfSprite_setTexture(new->sprite, new->texture, 1);
    new->pos.x = c.x - 50;
    new->pos.y = c.y - 50;
    new->save_pos.x = c.x;
    new->save_pos.y = c.y;
    new->pos_aura.x = c.x - 110;
    new->pos_aura.y = c.y - 100;
    return (new);
}

enemy_t *push_def(game_t *game, char *image, char *aura, int cost)
{
    enemy_t *new = malloc(sizeof(enemy_t));
    sfVector2i c = sfMouse_getPositionRenderWindow(game->window);
    enemy_t *tmp;

    add_aura(c, aura, image, new);
    new->cost = cost;
    new->texture2 = sfTexture_createFromFile(aura, NULL);
    sfSprite_setTexture(new->sprite2, new->texture2, 1);
    new->rect = (sfIntRect) {0, 0, 200, 200};
    sfSprite_setTextureRect(new->sprite2, new->rect);
    sfSprite_setPosition(new->sprite, new->pos);
    sfSprite_setPosition(new->sprite2, new->pos_aura);
    new->next = NULL;
    if (!game->tmp)
        return (new);
    tmp = game->tmp;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    } tmp->next = new;
    return (game->tmp);
}
