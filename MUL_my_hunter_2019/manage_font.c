/*
** EPITECH PROJECT, 2019
** my hunter
** File description:
** manage font
*/
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"

void cursor_sprite(struct framebuffer *op)
{
    op->c = sfMouse_getPositionRenderWindow(op->window);
    sfSprite_setPosition(op->sp_c, (sfVector2f) {op->c.x - 18, op->c.y - 18});
    sfSprite_setTexture(op->sp_c, op->text_c, sfTrue);
    sfRenderWindow_drawSprite(op->window, op->sp_c, NULL);
}

void get_backg(struct framebuffer op)
{
    sfSprite_setTexture(op.back, op.font, 1);
    sfRenderWindow_drawSprite(op.window, op.back, NULL);
    sfSprite_setPosition(op.sprite, op.position_duck);
    sfSprite_setTexture(op.sprite, op.texture, sfTrue);
    sfSprite_setTextureRect(op.sprite, op.rect);
    sfRenderWindow_drawSprite(op.window, op.sprite, NULL);
    sfText_setString(op.display_life, "LifePoint :");
    sfText_setString(op.display_score, "Score :");
    sfText_setPosition(op.display_score, op.pos_text);
    sfText_setPosition(op.display_life, op.pos_life);
    sfText_setString(op.text, itoa(op.score));
    sfText_setString(op.life_text, itoa(op.life));
    op.pos_text.x += 150;
    op.pos_life.x += 200;
    sfText_setPosition(op.text, op.pos_text);
    sfText_setPosition(op.life_text, op.pos_life);
    sfRenderWindow_drawText(op.window, op.text, NULL);
    sfRenderWindow_drawText(op.window, op.life_text, NULL);
    sfRenderWindow_drawText(op.window, op.display_score, NULL);
    sfRenderWindow_drawText(op.window, op.display_life, NULL);
}
