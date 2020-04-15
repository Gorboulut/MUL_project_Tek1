/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** creation of the game
*/
#include "include/my_defender.h"

aura_t *push_aura(game_t *game, char *text)
{
    aura_t *new = malloc(sizeof(aura_t));
    aura_t *tmp;

    new->spr = sfSprite_create();
    new->tex = sfTexture_createFromFile(text, NULL);
    new->n = NULL;
    if (!game->au)
        return (new);
    tmp = game->au;
    while (tmp->n != NULL) {
        tmp = tmp->n;
    }
    tmp->n = new;
    return (game->au);
}

void call_my_malloc(game_t *game)
{
    game->loose = malloc(sizeof(play_t));
    game->print_win = malloc(sizeof(play_t));
    game->win = malloc(sizeof(play_t));
    game->play = malloc(sizeof(play_t));
    game->enemy = malloc(sizeof(enemy_t));
    game->music = malloc(sizeof(music_t));
    game->tmp = malloc(sizeof(enemy_t));
    game->au = malloc(sizeof(aura_t));
    game->option = malloc(sizeof(play_t));
    game->text = malloc(sizeof(text_t));
    game->diff = malloc(sizeof(diff_t));
    game->htp = malloc(sizeof(play_t));
    game->pause = malloc(sizeof(play_t));
    game->sound = malloc(sizeof(sound_t));
}

void create_my_sprite(game_t *game)
{
    game->loose->sprite = sfSprite_create();
    game->print_win->sprite = sfSprite_create();
    game->win->sprite = sfSprite_create();
    game->play->sprite = sfSprite_create();
    game->enemy->sprite = sfSprite_create();
    game->option->sprite = sfSprite_create();
    game->htp->sprite = sfSprite_create();
    game->pause->sprite = sfSprite_create();
}

void create_my_sound(game_t *game)
{
    game->sound->corona = sfSound_create();
    game->sound->minis = sfSound_create();
    game->sound->hospi = sfSound_create();
    game->sound->winnie = sfSound_create();
    game->sound->buffer_c = sfSoundBuffer_createFromFile("src/beer.wav");
    game->sound->buffer_m = sfSoundBuffer_createFromFile("src/war.wav");
    game->sound->buffer_h = sfSoundBuffer_createFromFile("src/wololo.wav");
    game->sound->buffer_w = sfSoundBuffer_createFromFile("src/beer.wav");
    sfSound_setBuffer(game->sound->corona, game->sound->buffer_c);
    sfSound_setBuffer(game->sound->minis, game->sound->buffer_m);
    sfSound_setBuffer(game->sound->hospi, game->sound->buffer_h);
    sfSound_setBuffer(game->sound->winnie, game->sound->buffer_w);
}

void create_my_texture(game_t *game)
{
    game->loose->texture = sfTexture_createFromFile("src/lose.jpg", NULL);
    game->win->texture = sfTexture_createFromFile("src/menu.png", NULL);
    game->enemy->texture = sfTexture_createFromFile("src/avion.png", NULL);
    game->play->texture = sfTexture_createFromFile("src/map_normal.jpg", NULL);
    game->option->texture = sfTexture_createFromFile("src/option.jpg", NULL);
    game->au = NULL;
    game->tmp = NULL;
    game->au = push_aura(game, "src/aura_mouse_on.png");
    game->au = push_aura(game, "src/arrow_left.png");
    game->au = push_aura(game, "src/arrow_right.png");
    game->htp->texture = sfTexture_createFromFile("src/htp_menu.jpg", NULL);
    game->print_win->texture = sfTexture_createFromFile("src/win.jpg", NULL);
    game->pause->texture = sfTexture_createFromFile("src/pause.jpg", NULL);
}
