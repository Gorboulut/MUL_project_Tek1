/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** initialisation.c
*/

#include "include/my_defender.h"

void game_init(game_t *game)
{
    game->release = 0;
    game->value = 0;
    game->lose = 0;
    game->bool = 0;
    game->turret = 1;
    game->money = 30;
    game->money = 10;
    game->nb_enemy = 10;
    game->time = 1;
    game->nb_wave = 0;
    game->speed = 1;
}