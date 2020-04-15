/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** background for runner
*/

#include "include/my.h"

void check_pos_backg(back **back)
{
    if ((*back)->position_text2.x < -1270)
        (*back)->position_text2.x = 1270;
    if ((*back)->position_text3.x < -1270)
        (*back)->position_text3.x = 1270;
    if ((*back)->position_text4.x < -1270)
        (*back)->position_text4.x = 1270;
    if ((*back)->position_text_sec2.x < -1270)
        (*back)->position_text_sec2.x = 1270;
    if ((*back)->position_text_sec3.x < -1270)
        (*back)->position_text_sec3.x = 1270;
    if ((*back)->position_text_sec4.x < -1270)
        (*back)->position_text_sec4.x = 1270;
    if ((*back)->position_ground.x < -1195)
        (*back)->position_ground.x = 1195;
    if ((*back)->position_ground2.x < -1195)
        (*back)->position_ground2.x = 1195;
}

void check_pos_sec_backg(back **back)
{
    sfSprite_setTexture((*back)->sprite_sec2, (*back)->texture2, 1);
    sfSprite_setTexture((*back)->sprite_sec3, (*back)->texture3, 1);
    sfSprite_setTexture((*back)->sprite_sec4, (*back)->texture4, 1);
    sfSprite_setPosition((*back)->sprite_sec2, (*back)->position_text_sec2);
    sfSprite_setPosition((*back)->sprite_sec3, (*back)->position_text_sec3);
    sfSprite_setPosition((*back)->sprite_sec4, (*back)->position_text_sec4);
    sfSprite_setPosition((*back)->sprite_ground, (*back)->position_ground);
    sfSprite_setPosition((*back)->sprite_gr_sec, (*back)->position_ground2);
}

void backg_speed(back **back)
{
    (*back)->text_time = sfClock_getElapsedTime((*back)->text_clock);
    (*back)->text_speed = (*back)->text_time.microseconds / 1000000.0;
    if ((*back)->text_speed > 0.01) {
        (*back)->position_text2.x -= 1.5;
        (*back)->position_text3.x -= 2;
        (*back)->position_text4.x -= 2.5;
        (*back)->position_text_sec2.x -= 1.5;
        (*back)->position_text_sec3.x -= 2;
        (*back)->position_text_sec4.x -= 2.5;
        (*back)->position_ground.x -= 3;
        (*back)->position_ground2.x -= 3;
        sfClock_restart((*back)->text_clock);
    }
}

void put_backg(back *back)
{
    sfSprite_setTexture(back->sprite, back->texture, 1);
    sfSprite_setTexture(back->sprite2, back->texture2, 1);
    sfSprite_setTexture(back->sprite3, back->texture3, 1);
    sfSprite_setTexture(back->sprite4, back->texture4, 1);
    sfSprite_setTexture(back->sprite_ground, back->texture_ground, 1);
    sfSprite_setTexture(back->sprite_gr_sec, back->texture_ground, 1);
    sfSprite_setPosition(back->sprite2, back->position_text2);
    sfSprite_setPosition(back->sprite3, back->position_text3);
    sfSprite_setPosition(back->sprite4, back->position_text4);
    sfRenderWindow_drawSprite(back->window, back->sprite, NULL);
    sfRenderWindow_drawSprite(back->window, back->sprite_sec2, NULL);
    sfRenderWindow_drawSprite(back->window, back->sprite2, NULL);
    sfRenderWindow_drawSprite(back->window, back->sprite3, NULL);
    sfRenderWindow_drawSprite(back->window, back->sprite_sec3, NULL);
    sfRenderWindow_drawSprite(back->window, back->sprite4, NULL);
    sfRenderWindow_drawSprite(back->window, back->sprite_sec4, NULL);
    sfRenderWindow_drawSprite(back->window, back->sprite_ground, NULL);
    sfRenderWindow_drawSprite(back->window, back->sprite_gr_sec, NULL);
}

void get_backg(back *back)
{
    check_pos_sec_backg(&back);
    put_backg(back);
    check_pos_backg(&back);
    backg_speed(&back);
}
