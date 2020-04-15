/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** manage life
*/
#include "include/my.h"

void game_over_screen(struct framebuffer *op, sfEvent event)
{
    op->menu_nbr++;
    sfRenderWindow_setMouseCursorVisible(op->window, 1);
    while (op->menu_nbr == 3 && sfRenderWindow_isOpen(op->window)) {
        sfSprite_setTexture(op->end_spr, op->end_text, 1);
        sfRenderWindow_drawSprite(op->window, op->end_spr, NULL);
        sfRenderWindow_display(op->window);
        analyse_events(op, event);
    }
}

void check_life(struct framebuffer *op, sfEvent event)
{
    if (op->position_duck.x > 1080) {
        op->life--;
        op->position_duck.x = -110;
        op->position_duck.y = rand() % 569;
        if (op->life == 0) {
            game_over_screen(op, event);
            op->life = 3;
            op->menu_nbr = 2;
            op->score = 0;
            op->speed = 0.1;
            sfRenderWindow_setMouseCursorVisible(op->window, 0);
        }
    }
}
