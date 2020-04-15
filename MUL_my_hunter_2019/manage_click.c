/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** manage mouse click
*/
#include "include/my.h"

void manage_mouse_click(struct framebuffer **op)
{
    sfVector2i click = sfMouse_getPositionRenderWindow((*op)->window);

    if (click.x <= (*op)->position_duck.x + 110 &&
        click.x >= (*op)->position_duck.x -110 &&
        click.y <= (*op)->position_duck.y + 110 &&
        click.y >= (*op)->position_duck.y) {
        (*op)->position_duck.x = -110;
        (*op)->position_duck.y = rand() % 569;
        (*op)->speed += 0.5;
        (*op)->score++;
    }
    if (click.x > 14 && click.x < 1040 && click.y > 271 && click.y < 480
        && (*op)->menu_nbr == 1)
        (*op)->menu_nbr++;
    if (click.x > 390 && click.x < 790 && click.y > 190 && click.y < 270
        && (*op)->menu_nbr == 3)
        (*op)->menu_nbr--;
    if (click.x > 390 && click.x < 790 && click.y > 330 && click.y < 420
        && (*op)->menu_nbr == 3)
        sfRenderWindow_close((*op)->window);
}

void move_rect(struct framebuffer *op)
{
    if (op->rect.left >= 220)
        op->offset = -1;
    else if (op->rect.left == 0)
        op->offset = 1;
    op->rect.left = op->rect.left + 106 * op->offset;
}
