/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csfml start
*/
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"

void analyse_events(struct framebuffer *op, sfEvent event)
{
    while (sfRenderWindow_pollEvent(op->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(op->window);
        if (event.mouseButton.button == sfMouseLeft) {
            manage_mouse_click(&op);
        }
    }
}

void get_speed(struct framebuffer *op)
{
    op->time_spr = sfClock_getElapsedTime(op->spr_clock);
    op->spr_mv = op->time_spr.microseconds / 1000000.0;
    if (op->spr_mv > 0.01) {
        op->position_duck.x += op->speed;
        sfClock_restart(op->spr_clock);
    }
}

void get_game(struct framebuffer op, sfTime time, sfEvent event, sfClock *clok)
{
    op.music2 = sfMusic_createFromFile("tnt_doom.ogg");
    sfMusic_play(op.music2);
    sfRenderWindow_setMouseCursorVisible(op.window, 0);
    while (sfRenderWindow_isOpen(op.window)) {
        get_backg(op);
        cursor_sprite(&op);
        time = sfClock_getElapsedTime(clok);
        op.seconds = time.microseconds / 1000000.0;
        sfRenderWindow_display(op.window);
        analyse_events(&op, event);
        get_speed(&op);
        check_life(&op, event);
        if (op.seconds > 0.3) {
            move_rect(&op);
            sfClock_restart(clok);
        }
    }
    sfMusic_destroy(op.music2);
}

void call_hunt(struct framebuffer op)
{
    sfClock *clock = sfClock_create();
    sfTime time;
    sfEvent event;

    sfMusic_play(op.music);
    while (sfRenderWindow_isOpen(op.window)) {
        if (op.menu_nbr == 1) {
            sfSprite_setTexture(op.menu, op.menu_texture, 1);
            sfRenderWindow_drawSprite(op.window, op.menu, NULL);
            sfRenderWindow_display(op.window);
            analyse_events(&op, event);
        }
        if (op.menu_nbr == 2) {
            sfMusic_destroy(op.music);
            get_game(op, time, event, clock);
        }
    }
    sfRenderWindow_destroy(op.window);
}

int main(int ac, char **av)
{
    struct framebuffer op;

    if (ac == 2)
        if (av[1][0] == '-' && av[1][1] == 'h') {
            display_help();
            return (0);
        }
    if (ac > 2)
        return (84);
    init_struc1(op);
    return (0);
}
