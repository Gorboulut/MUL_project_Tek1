/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** init struc
*/
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"

void init_struc3(struct framebuffer op)
{
    op.end_spr = sfSprite_create();
    op.end_text = sfTexture_createFromFile("game_over.png", NULL);
    op.display_life = sfText_create();
    op.display_score = sfText_create();
    sfText_setFont(op.display_life, op.fontext);
    sfText_setFont(op.display_score, op.fontext);
    sfText_setCharacterSize(op.display_score, 40);
    sfText_setCharacterSize(op.display_life, 40);
    call_hunt(op);
}

void init_struc2(struct framebuffer op)
{
    op.fontext = sfFont_createFromFile("arial.ttf");
    op.text = sfText_create();
    sfText_setFont(op.text, op.fontext);
    sfText_setCharacterSize(op.text, 40);
    op.life_text = sfText_create();
    sfText_setFont(op.life_text, op.fontext);
    sfText_setCharacterSize(op.life_text, 40);
    op.life = 3;
    op.speed = 1;
    op.score = 0;
    op.pos_text.x = 850;
    op.pos_text.y = 0;
    op.pos_life.x = 30;
    op.pos_life.y = 0;
    op.menu_texture = sfTexture_createFromFile("menu_font.png", NULL);
    op.menu = sfSprite_create();
    op.menu_nbr = 1;
    op.offset = 1;
    op.spr_clock = sfClock_create();
    init_struc3(op);
}

void init_struc1(struct framebuffer op)
{
    sfVideoMode mode = {1080, 718, 32};

    op.offset = 1;
    op.rect.left = 0;
    op.rect.top = 0;
    op.rect.width = 108;
    op.rect.height = 108;
    op.back = sfSprite_create();
    op.sprite = sfSprite_create();
    op.window = sfRenderWindow_create(mode, "Pony Hunt", sfDefaultStyle, NULL);
    op.font = sfTexture_createFromFile("game_font.png", NULL);
    op.sprite = sfSprite_create();
    op.texture = sfTexture_createFromFile("my_poney.png", NULL);
    op.position_duck.y = rand() % 569;
    op.position_duck.x = -110;
    op.text_c = sfTexture_createFromFile("cursor.png", NULL);
    op.sp_c = sfSprite_create();
    op.music = sfMusic_createFromFile("tnt_evil.ogg");
    init_struc2(op);
}
