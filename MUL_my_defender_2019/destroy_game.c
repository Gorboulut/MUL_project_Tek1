/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** destroy_game.c
*/

#include "include/my_defender.h"

void destroy_game(game_t *game)
{
    sfSprite_destroy(game->loose->sprite);
    sfSprite_destroy(game->win->sprite);
    sfSprite_destroy(game->play->sprite);
    if (game->enemy)
        sfSprite_destroy(game->enemy->sprite);
    sfMusic_destroy(game->music->music_menu);
    sfMusic_destroy(game->music->game_music);
    sfRenderWindow_destroy(game->window);
    sfSound_destroy(game->sound->corona);
    sfSound_destroy(game->sound->minis);
    sfSound_destroy(game->sound->hospi);
    sfSound_destroy(game->sound->winnie);
    sfSoundBuffer_destroy(game->sound->buffer_c);
    sfSoundBuffer_destroy(game->sound->buffer_m);
    sfSoundBuffer_destroy(game->sound->buffer_h);
    sfSoundBuffer_destroy(game->sound->buffer_w);
}
