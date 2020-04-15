/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** check_hit
*/
#include "include/my.h"

int check_hit(back *back, map *mp, trap *tr)
{
    if ((mp->position_uni.x + 150 > tr->position_trap.x
        && mp->position_uni.x + 150 < tr->position_trap.x + 60)
        && (mp->position_uni.y > tr->position_trapt.y
        || mp->position_uni.y > tr->position_trap.y))
            tr->life--;
}

void call_destroy(menu *menu)
{
    sfMusic_destroy(menu->sound_jump);
}
