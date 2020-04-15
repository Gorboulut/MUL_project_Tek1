/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** game_events.c
*/

#include "include/my_defender.h"

void put_def_on_map(game_t *game, sfVector2i c)
{
    if (c.y < 860) {
        if (game->turret == 1 && game->money >= 5) {
            game->tmp = push_def(game, "src/ministre.png", "src/aura2.png", 5);
            game->money -= 5;
            sfSound_play(game->sound->minis);
        } if (game->turret == 2 && game->money >= 10) {
            game->tmp = push_def(game, "src/corona.png", "src/aura2.png", 10);
            game->money -= 10;
            sfSound_play(game->sound->corona);
        } if (game->turret == 3 && game->money >= 15) {
            game->tmp = push_def(game, "src/hopital.png", "src/aura.png", 15);
            game->money -= 15;
            sfSound_play(game->sound->hospi);
        } if (game->turret == 4 && game->money >= 20) {
            game->tmp = push_def(game, "src/winnie.png", "src/aura2.png", 20);
            game->money -= 20;
            sfSound_play(game->sound->winnie);
        } game->tmp->pos.x = c.x - 160;
        game->tmp->pos.y = c.y - 130;
        game->tmp->save_pos.x = c.x;
        game->tmp->save_pos.y = c.y;
    }
}

void check_volume_change(game_t *game, sfVector2i c)
{
    if (c.x > 650 && c.x < 750 && c.y > 800 && c.y < 900) {
        game->volume = game->volume->prev;
        sfMusic_setVolume(game->music->music_menu, game->volume->vol);
        sfMusic_setVolume(game->music->game_music, game->volume->vol);
        game->release = 2;
    } if (c.x > 940 && c.x < 1040 && c.y > 800 && c.y < 900) {
        game->volume = game->volume->next;
        sfMusic_setVolume(game->music->music_menu, game->volume->vol);
        sfMusic_setVolume(game->music->game_music, game->volume->vol);
        game->release = 5;
    } if (c.x > 525 && c.x < 590 && c.y > 430 && c.y < 510) {
        game->diff = game->diff->prev;
        game->release = 2;
    } if (c.x > 1040 && c.x < 1100 && c.y > 430 && c.y < 510) {
        game->diff = game->diff->next;
        game->release = 5;
    } if (c.x > 100 && c.x < 250 && c.y > 850 && c.y < 980)
        game->menu = 0;
}

void check_turret(game_t *game, sfVector2i c)
{
    if (c.x > 600 && c.x < 720 && c.y > 860)
        game->turret = 1;
    if (c.x > 720 && c.x < 850 && c.y > 860)
        game->turret = 2;
    if (c.x > 850 && c.x < 980 && c.y > 860)
        game->turret = 3;
    if (c.x > 980 && c.x < 1110 && c.y > 860)
        game->turret = 4;
}

void manage_click(game_t *game)
{
    sfVector2i c = sfMouse_getPositionRenderWindow(game->window);

    if (game->menu == 2) {
        put_def_on_map(game, c);
        check_turret(game, c);
    }
    click(game, c);
    if (c.x > 600 && c.x < 1100 && c.y < 320 && c.y > 220 && game->menu == 0)
        game->menu = 2;
    if (c.x > 600 && c.x < 1100 && c.y < 820 && c.y > 720 && game->menu == 0)
        sfRenderWindow_close(game->window);
    if (c.x > 600 && c.x < 1100 && c.y < 550 && c.y > 450 && game->menu == 0)
        game->menu = 1;
    if (c.x > 1440 && c.x < 1700 && c.y < 70 && c.y > 0 && game->menu == 0)
        game->menu = 5;
    if (c.x > 300 && c.x < 970 && c.y > 420 && c.y < 550 && game->menu == 4)
        game->menu = 0;
    if (c.x > 100 && c.x < 250 && c.y > 850 && c.y < 980 && game->menu == 5)
        game->menu = 0;
    if (game->menu == 1)
        check_volume_change(game, c);
}

void game_events(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue && game->menu == 2)
            game->menu = 6;
        if (game->event.type == sfEvtMouseButtonPressed)
            if (game->event.mouseButton.button == sfMouseLeft)
                manage_click(game);
        if (game->event.type == sfEvtMouseButtonReleased)
            game->release = 0;
    }
    game->money_print = my_itoa(game->money);
    sfText_setString(game->text->text, game->money_print);
}
