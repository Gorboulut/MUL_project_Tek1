/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** runner game in csfml
*/
#include "include/my.h"

void move_rect(map **op)
{
    if ((*op)->rect_uni.top == 0 && (*op)->rect_uni.left <= 300) {
        (*op)->rect_uni.left = 605;
        (*op)->rect_uni.top = 330;
    }
    if ((*op)->rect_uni.left <= 200) {
        (*op)->rect_uni.left = 1840;
        (*op)->rect_uni.top -= 110;
    }
    (*op)->rect_uni.left = (*op)->rect_uni.left - 206;
}

void score_display(map **map, back **back)
{
    sfText_setString((*map)->text, itoa((*map)->score));
    sfText_setString((*map)->display_score, "Score :");
    sfText_setPosition((*map)->text, (*map)->pos_score);
    sfText_setPosition((*map)->display_score, (*map)->pos_text);
    sfRenderWindow_drawText((*back)->window, (*map)->text, NULL);
    sfRenderWindow_drawText((*back)->window, (*map)->display_score, NULL);
}

void jump_manag(map *map)
{
    if (map->jump == 1 && map->position_uni.y < 400)
        map->position_uni.y -= 13;
    if (map->position_uni.y <= 150)
        map->jump = 0;
    if (map->jump == 0 && map->position_uni.y != 390)
        map->position_uni.y += 13;
    move_rect(&map);
    map->score += 1;
}

void load_sprite(map *map, back *back, menu *menu)
{
    int static i = 0;

    sfSprite_setTexture(map->uni, map->text_uni, 1);
    sfSprite_setTextureRect(map->uni, map->rect_uni);
    sfSprite_setPosition(map->uni, map->position_uni);
    sfRenderWindow_drawSprite(back->window, map->uni, NULL);
    map->uni_time = sfClock_getElapsedTime(map->uni_clock);
    map->uni_speed = map->uni_time.microseconds / 1000000.0;
    score_display(&map, &back);
    if (map->jump == 1 && i == 29)
        sfMusic_play(menu->sound_jump);
    if (i == 1)
        sfMusic_stop(menu->sound_jump);
    if (map->uni_speed > 0.035) {
        jump_manag(map);
        if (map->jump == 1 && i <= 0)
            i = 30;
        i--;
        sfClock_restart(map->uni_clock);
    }
}
