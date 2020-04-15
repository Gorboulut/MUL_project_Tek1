/*
** EPITECH PROJECT, 2019
** my runner
** File description:
** csfml game
*/
#include "include/my.h"

void analyse_event(back *back, map *map, menu *menu, trap *trap)
{
    while (sfRenderWindow_pollEvent(back->window, &menu->event)) {
        if (menu->event.type == sfEvtClosed)
            sfRenderWindow_close(back->window);
        if (sfKeyboard_isKeyPressed(sfKeyUp) && map->position_uni.y == 390)
            map->jump = 1;
        if (menu->event.mouseButton.button == sfMouseLeft)
            manage_mouse_click(&menu, &back, &trap, &map);
    }
}

void the_game(back *back, map *mp, trap *trap, menu *menu)
{
    if (menu->menu == 1) {
        get_backg(back);
        load_sprite(mp, back, menu);
        check_map(back, mp, trap);
        check_hit(back, mp, trap);
        analyse_event(back, mp, menu, trap);
        sfRenderWindow_display(back->window);
    }
}

void show_win(back *back, map *mp, menu *menu)
{
    sfSprite_setTexture(menu->win_spr, menu->win_tex, 1);
    sfRenderWindow_drawSprite(back->window, menu->win_spr, NULL);
    sfRenderWindow_display(back->window);
}

void launch_game(back back, map mp, trap trap, menu menu)
{
    get_menu(&menu);
    sfMusic_play(menu.music_menu);
    while (sfRenderWindow_isOpen(back.window)) {
        if (trap.life > 0) {
            first_menu(&back, &mp, &menu, &trap);
            the_game(&back, &mp, &trap, &menu);
        }
        if (trap.life <= 0) {
            menu.menu = 2;
            show_defeat(&back, &mp, &menu);
            analyse_event(&back, &mp, &menu, &trap);
        }
        if (mp.mp[mp.i] == '\0' && trap.life > 0) {
            menu.menu = 2;
            show_win(&back, &mp, &menu);
            analyse_event(&back, &mp, &menu, &trap);
        }
    }
    call_destroy(&menu);
}

int main(int ac, char **av)
{
    struct back back;

    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h') {
            my_helper();
            return (1);
        }
        init_struct(back, av);
        return (1);
    }
    return (84);
}
