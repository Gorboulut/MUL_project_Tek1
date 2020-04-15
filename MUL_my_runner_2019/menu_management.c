/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** menu management for runner game
*/
#include "include/my.h"

void manage_mouse_click(menu **menu, back **back, trap **trap, map **mp)
{
    sfVector2i click = sfMouse_getPositionRenderWindow((*back)->window);

    if (click.x > 335 && click.x < 888 && click.y > 471 && click.y < 520
    && (*menu)->menu == 0)
        (*menu)->menu = 1;
    if (click.x > 60 && click.x < 320 && click.y > 360 && click.y < 400
    && (*menu)->menu == 2) {
        (*menu)->menu = 1;
        (*trap)->life = 1;
        (*trap)->position_trap.x = -100;
        (*trap)->position_trapt.x = -100;
        (*mp)->score = 0;
        (*mp)->i = 0;
    }
    if (click.x > 945 && click.x < 1110 && click.y > 360 && click.y < 400
    && (*menu)->menu == 2) {
        sfMusic_destroy((*menu)->sound_run);
        sfMusic_destroy((*menu)->music_game);
        sfRenderWindow_close((*back)->window);
    }
}

void get_menu(menu *menu)
{
    menu->music_menu = sfMusic_createFromFile("menu_music.ogg");
    menu->sound_run = sfMusic_createFromFile("tagada.ogg");
    menu->sound_jump = sfMusic_createFromFile("jump.ogg");
    menu->music_game = sfMusic_createFromFile("music.ogg");
    menu->win_spr = sfSprite_create();
    menu->loose_spr = sfSprite_create();
    menu->start_spr = sfSprite_create();
    menu->win_tex = sfTexture_createFromFile("victory.png", NULL);
    menu->loose_tex = sfTexture_createFromFile("defeat.jpg", NULL);
    menu->start_tex = sfTexture_createFromFile("menu.png", NULL);
    menu->menu = 0;
}

void display_menu(menu *menu, back *back, sfEvent event)
{
    sfSprite_setTexture(menu->start_spr, menu->start_tex, 1);
    sfRenderWindow_drawSprite(back->window, menu->start_spr, NULL);
    sfRenderWindow_display(back->window);
}

void first_menu(back *back, map *mp, menu *menu, trap *trap)
{
    if (menu->menu == 0) {
        display_menu(menu, back, menu->event);
        analyse_event(back, mp, menu, trap);
        if (menu->menu == 1) {
            sfMusic_destroy(menu->music_menu);
            sfMusic_setVolume(menu->music_game, 20);
            sfMusic_setVolume(menu->sound_run, 30);
            sfMusic_play(menu->sound_run);
            sfMusic_play(menu->music_game);
        }
    }
}

void show_defeat(back *back, map *mp, menu *menu)
{
    sfSprite_setTexture(menu->loose_spr, menu->loose_tex, 1);
    sfRenderWindow_drawSprite(back->window, menu->loose_spr, NULL);
    sfRenderWindow_display(back->window);
}
