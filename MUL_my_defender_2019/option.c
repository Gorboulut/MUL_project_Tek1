/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** option for defender
*/
#include "include/my_defender.h"

void check_quad_aura(game_t *game, sfVector2f pos, sfVector2i c)
{
    if (c.x > 525 && c.x < 590 && c.y > 430 && c.y < 510) {
        pos.x = 510;
        pos.y = 503;
        sfSprite_setTexture(game->au->spr, game->au->tex, 1);
        sfSprite_setPosition(game->au->spr, pos);
        sfRenderWindow_drawSprite(game->window, game->au->spr, NULL);
        if (game->release == 2) {
            pos.y -= 55;
            pos.x += 25;
            sfSprite_setTexture(game->au->n->spr, game->au->n->tex, 1);
            sfSprite_setPosition(game->au->n->spr, pos);
            sfRenderWindow_drawSprite(game->window, game->au->n->spr, NULL);
        }
    }
}

void check_third_aura(game_t *game, sfVector2f pos, sfVector2i c)
{
    if (c.x > 1040 && c.x < 1100 && c.y > 430 && c.y < 510) {
        pos.x = 1025;
        pos.y = 503;
        sfSprite_setTexture(game->au->spr, game->au->tex, 1);
        sfSprite_setPosition(game->au->spr, pos);
        sfRenderWindow_drawSprite(game->window, game->au->spr, NULL);
        if (game->release == 5) {
            pos.y -= 52;
            pos.x += 27;
            sfSprite_setTexture(game->au->n->n->spr, game->au->n->n->tex, 1);
            sfSprite_setPosition(game->au->n->n->spr, pos);
            sfRenderWindow_drawSprite(game->window, game->au->n->n->spr, NULL);
        }
    }
    check_quad_aura(game, pos, c);
}

void check_aura_second(game_t *game, sfVector2f pos, sfVector2i c)
{
    if (c.x > 940 && c.x < 1040 && c.y > 800 && c.y < 900) {
        pos.x = 935;
        pos.y = 855;
        sfSprite_setTexture(game->au->spr, game->au->tex, 1);
        sfSprite_setPosition(game->au->spr, pos);
        sfRenderWindow_drawSprite(game->window, game->au->spr, NULL);
        if (game->release == 5) {
            pos.y -= 45;
            pos.x += 30;
            sfSprite_setTexture(game->au->n->n->spr, game->au->n->n->tex, 1);
            sfSprite_setPosition(game->au->n->n->spr, pos);
            sfRenderWindow_drawSprite(game->window, game->au->n->n->spr, NULL);
        }
    }
    check_third_aura(game, pos, c);
}

void check_aura(game_t *game)
{
    sfVector2i c = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f pos;

    if (c.x > 650 && c.x < 750 && c.y > 800 && c.y < 900) {
        pos.x = 635;
        pos.y = 850;
        sfSprite_setTexture(game->au->spr, game->au->tex, 1);
        sfSprite_setPosition(game->au->spr, pos);
        sfRenderWindow_drawSprite(game->window, game->au->spr, NULL);
        if (game->release == 2) {
            pos.y -= 36;
            pos.x += 25;
            sfSprite_setTexture(game->au->n->spr, game->au->n->tex, 1);
            sfSprite_setPosition(game->au->n->spr, pos);
            sfRenderWindow_drawSprite(game->window, game->au->n->spr, NULL);
        }
    }
    check_aura_second(game, pos, c);
}

void call_option(game_t *game)
{
    sfSprite_setTexture(game->option->sprite, game->option->texture, 1);
    sfRenderWindow_drawSprite(game->window, game->option->sprite, NULL);
    sfSprite_setPosition(game->volume->sprite, game->volume->pos);
    sfSprite_setPosition(game->diff->sprite, game->diff->pos);
    sfSprite_setTexture(game->diff->sprite, game->diff->texture, 1);
    sfSprite_setTexture(game->volume->sprite, game->volume->texture, 1);
    sfRenderWindow_drawSprite(game->window, game->volume->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->diff->sprite, NULL);
    check_aura(game);
}
