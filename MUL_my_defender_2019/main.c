/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** main.c
*/
#include "include/my_defender.h"

void sec_menu(game_t *game)
{
    if (game->menu == 6)
        make_pause(game);
    if (game->menu == 7)
        make_lose(game);
    if (game->menu == 8)
        make_win(game);
}

void get_menu(game_t *game)
{
    if (game->menu == 0)
        call_menu(game);
    if (game->menu != 0 && game->menu != 1 && game->value == 0) {
        sfMusic_stop(game->music->music_menu);
        sfMusic_play(game->music->game_music);
    }
    if (game->menu == 1)
        call_option(game);
    if (game->menu == 2) {
        call_play(game);
        game->value++;
    }
    if (game->menu == 4)
        call_loose(game);
    if (game->menu == 5) {
        sfSprite_setTexture(game->htp->sprite, game->htp->texture, 1);
        sfRenderWindow_drawSprite(game->window, game->htp->sprite, NULL);
    }
    sec_menu(game);
}

int main(void)
{
    game_t *game = malloc(sizeof(game_t));
    float elapsed;
    sfClock *clock = sfClock_create();

    create_game(game);
    game->menu = 0;
    sfMusic_play(game->music->music_menu);
    while (sfRenderWindow_isOpen(game->window)) {
        elapsed = sfClock_getElapsedTime(clock).microseconds / 1000000.0;
        sfClock_restart(clock);
        game_events(game);
        game_update(game, elapsed);
        game_render(game);
    }
    destroy_game(game);
    return (0);
}
