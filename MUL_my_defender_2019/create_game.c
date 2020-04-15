/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** create_game.c
*/
#include "include/my_defender.h"

vol_t *push_vol(game_t *game, int vol, char *text)
{
    vol_t *new = malloc(sizeof(vol_t));
    vol_t *tmp;

    new->vol = vol;
    new->sprite = sfSprite_create();
    new->texture = sfTexture_createFromFile(text, NULL);
    new->pos.x = 650;
    new->pos.y = 800;
    new->next = NULL;
    new->prev = NULL;
    if (!game->volume)
        return (new);
    tmp = game->volume;
    while (tmp->next != NULL) {
        tmp->next->prev = tmp;
        tmp = tmp->next;
    } tmp->next = new;
    return (game->volume);
}

vol_t *make_it_double(game_t *game)
{
    vol_t *new = game->volume;

    new->next->prev = new;
    while (new->next != NULL) {
        new->next->prev = new;
        new = new->next;
    }
    new->next = game->volume;
    new->next->prev = new;
    return (new);
}

void create_vol(game_t *game)
{
    game->volume = NULL;
    game->volume = push_vol(game, 0, "src/vol_0.png");
    game->volume = push_vol(game, 30, "src/vol_30.png");
    game->volume = push_vol(game, 55, "src/Vol_55.png");
    game->volume = push_vol(game, 75, "src/Vol_75.png");
    game->volume = push_vol(game, 100, "src/Vol_100.png");
    game->volume = make_it_double(game);
    game->volume = game->volume->next;
}

void create_game(game_t *game)
{
    sfVideoMode mode = {1700, 980, 32};
    create_vol(game);
    call_my_malloc(game);
    create_my_sprite(game);
    create_my_texture(game);
    check_difficulty(game);
    create_my_sound(game);
    create_text(game);
    game_init(game);
    game->music->music_menu = sfMusic_createFromFile("src/menu_mus.ogg");
    game->music->game_music = sfMusic_createFromFile("src/game_mus.ogg");
    game->window = sfRenderWindow_create(mode, "Anti-Virus", sfClose, NULL);
    game->enemy = NULL;
}