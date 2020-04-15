/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** my_defender
*/
#ifndef INCLUDE_H
#define INCLUDE_H

#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Window/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Vector2.h>
#include <SFML/Audio.h>
#include <stddef.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>

#endif /* INCLUDE_H */

#ifndef STRUCT_H
#define STRUCT_H

typedef struct aura_s {
    sfSprite *spr;
    sfTexture *tex;
    struct aura_s *n;
} aura_t;

typedef struct play_s {
    sfSprite *sprite;
    sfTexture *texture;
} play_t;

typedef struct enemy_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfSprite *sprite2;
    sfTexture *texture2;
    sfVector2f pos;
    sfVector2f pos_aura;
    sfIntRect rect;
    sfVector2i save_pos;
    int cost;
    struct enemy_s *next;
} enemy_t;

typedef struct text_s {
    sfFont *fontext;
    sfText *text;
    sfVector2f pos;
    struct text_s *next;
} text_t;

typedef struct music_s {
    sfMusic *music_menu;
    sfMusic *game_music;
} music_t;

typedef struct sound_s {
    sfSoundBuffer *buffer_c;
    sfSoundBuffer *buffer_m;
    sfSoundBuffer *buffer_h;
    sfSoundBuffer *buffer_w;
    sfSound *corona;
    sfSound *minis;
    sfSound *hospi;
    sfSound *winnie;
} sound_t;

typedef struct diff_s {
    sfSprite *sprite;
    sfSprite *spr_map;
    sfTexture *texture;
    sfTexture *text_map;
    int diff;
    sfVector2f pos;
    struct diff_s *next;
    struct diff_s *prev;
} diff_t;

typedef struct vol_s {
    int vol;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    struct vol_s *next;
    struct vol_s *prev;
} vol_t;

typedef struct game_s {
    sfRenderWindow *window;
    float speed;
    int nb_wave;
    int menu;
    int turret;
    int kill;
    int money;
    char *money_print;
    float time;
    int lose;
    int bool;
    int nb_enemy;
    int value;
    sfEvent event;
    text_t *text;
    aura_t *au;
    play_t *play;
    play_t *loose;
    play_t *win;
    play_t *print_win;
    music_t *music;
    vol_t *volume;
    enemy_t *enemy;
    enemy_t *def;
    enemy_t *tmp;
    play_t *option;
    diff_t *diff;
    int release;
    play_t *htp;
    play_t *pause;
    sound_t *sound;
} game_t;

#endif /* STRUCT_H */

#ifndef DECLARATION_H
#define DECLARATION_H

void check_difficulty(game_t *game);
void create_game(game_t *game);
void game_events(game_t *game);
void game_update(game_t *game, float elapsed);
void game_render(game_t *game);
void get_menu(game_t *game);
void destroy_game(game_t *game);
void call_menu(game_t *game);
void call_loose(game_t *game);
int my_put_nbr(int nb);
void call_option(game_t *game);
void call_play(game_t *game);
void create_my_texture(game_t *game);
void create_my_sprite(game_t *game);
void call_my_malloc(game_t *game);
void position_enemy(game_t *game);
void create_enemy(game_t *game);
void call_option(game_t *game);
void create_def(game_t *game);
void position_def(game_t *game);
void call_htp(game_t *game);
enemy_t *push_def(game_t *game, char *image, char *aura, int cost);
void make_pause(game_t *game);
void pause_click(game_t *game, sfVector2i c);
void create_my_sound(game_t *game);
void make_lose(game_t *game);
void click(game_t *game, sfVector2i c);
void create_text(game_t *game);
void game_init(game_t *game);
void make_win(game_t *game);
char *my_itoa(int array);

#endif /* DECLARATION_H */
