/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** map management
*/
#include "include/my.h"

int launch_trap(back **back, map **mp, trap **tr)
{
    sfSprite_setTexture((*tr)->ttr, (*tr)->text_trapb, 1);
    sfSprite_setTexture((*tr)->btr, (*tr)->text_trapb, 1);
    sfSprite_setTextureRect((*tr)->ttr, (*tr)->rect_trapb);
    sfSprite_setTextureRect((*tr)->btr, (*tr)->rect_trapb);
    if ((*mp)->mp[(*mp)->i] == '2')  {
        (*tr)->position_trap.x = 1200;
        (*tr)->position_trapt.x = 1200;
    }
    sfSprite_setPosition((*tr)->ttr, (*tr)->position_trapt);
    sfSprite_setPosition((*tr)->btr, (*tr)->position_trap);
    sfRenderWindow_drawSprite((*back)->window, (*tr)->ttr, NULL);
    sfRenderWindow_drawSprite((*back)->window, (*tr)->btr, NULL);
}

void move_trap_rect(trap **op)
{
    if ((*op)->rect_trapb.left <= 550)
        (*op)->rect_trapb.left += 70;
    if ((*op)->rect_trapb.left >= 550)
        (*op)->rect_trapb.left = 233;
}

int check_map(back *back, map *map, trap *tr)
{
    tr->char_time = sfClock_getElapsedTime(tr->char_clock);
    tr->char_speed = tr->char_time.microseconds / 1000000.0;
    launch_trap(&back, &map, &tr);
    tr->trap_time = sfClock_getElapsedTime(tr->trap_clock);
    tr->trap_speed = tr->trap_time.microseconds / 1000000.0;
    if (tr->trap_speed > 0.02) {
        tr->position_trap.x -= 9;
        tr->position_trapt.x -= 9;
        sfClock_restart(tr->trap_clock);
    }
    if (tr->char_speed > 1) {
        map->i++;
        move_trap_rect(&tr);
        sfClock_restart(tr->char_clock);
    }
}
