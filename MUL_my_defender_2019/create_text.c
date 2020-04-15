/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** create_text.c
*/

#include "include/my_defender.h"

void create_text(game_t *game)
{
    game->text->fontext = sfFont_createFromFile("src/police.TTF");
    game->text->text = sfText_create();
    sfText_setFont(game->text->text, game->text->fontext);
    sfText_setPosition(game->text->text, (sfVector2f) {1460, 900});
    sfText_setCharacterSize(game->text->text, 50);
}