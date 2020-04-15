/*
** EPITECH PROJECT, 2019
** my h
** File description:
** my h
*/
#include <stdarg.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <sys/stat.h>
#include <fcntl.h>
#define EXIT_USAGE    84

typedef struct back {
    sfSprite *sprite;
    sfTexture *texture;
    sfSprite *sprite2;
    sfTexture *texture2;
    sfSprite *sprite3;
    sfTexture *texture3;
    sfSprite *sprite4;
    sfTexture *texture4;
    sfSprite *sprite_sec;
    sfSprite *sprite_sec2;
    sfSprite *sprite_sec3;
    sfSprite *sprite_sec4;
    sfClock *text_clock;
    float text_speed;
    sfTime text_time;
    sfTexture *texture_ground;
    sfSprite *sprite_ground;
    sfSprite *sprite_gr_sec;
    sfVector2f position_ground;
    sfVector2f position_ground2;
    sfVector2f position_text;
    sfVector2f position_text2;
    sfVector2f position_text3;
    sfVector2f position_text4;
    sfVector2f position_text_sec2;
    sfVector2f position_text_sec3;
    sfVector2f position_text_sec4;
    sfRenderWindow *window;
} back;

typedef struct menu {
    sfEvent event;
    int menu;
    sfMusic *music_menu;
    sfMusic *sound_jump;
    sfMusic *sound_run;
    sfMusic *music_game;
    sfSprite *win_spr;
    sfTexture *win_tex;
    sfSprite *loose_spr;
    sfTexture *loose_tex;
    sfSprite *start_spr;
    sfTexture *start_tex;
} menu;

typedef struct map {
    int menu;
    char *mp;
    int i;
    sfSprite *uni;
    int jump;
    int offset;
    sfTexture *text_uni;
    sfIntRect rect_uni;
    sfVector2f position_uni;
    sfTime uni_time;
    float uni_speed;
    sfClock *uni_clock;
    sfFont *fontext;
    sfText *text;
    sfText *display_score;
    int score;
    sfVector2f pos_text;
    sfVector2f pos_score;
} map;

typedef struct trap {
    int life;
    sfTime char_time;
    float char_speed;
    sfClock *char_clock;
    sfTime trap_time;
    sfSprite *ttr;
    sfSprite *btr;
    float trap_speed;
    sfClock *trap_clock;
    sfTexture *text_trapb;
    sfIntRect rect_trapb;
    sfTexture *text_trapt;
    sfIntRect rect_trapt;
    sfVector2f position_trap;
    sfVector2f position_traprem;
    sfVector2f position_trapt;
} trap;


void my_putchar(char c);
char *my_strcat(char *dest, char const *src);
int my_strlen(char const *str);
int my_put_nbr(int nb);
int my_putstr(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_revstr(char *str);
int my_atoi(char *str);
char *my_strdup(char const *src);
char *suppr_space(char *str);
int my_number(char *str);
char *my_realloc(char *str, char *fullstr, int len);
char *itoa(int n);
int my_helper(void);
void check_pos_backg(back **back);
void init_struct(back back, char **av);
void init_struct2(back back, char **av);
void get_backg(back *back);
void launch_game(back back, map mp, trap trap, menu menu);
void load_sprite(map *mp, back *back, menu *menu);
int check_map(back *back, map *map, trap *tr);
int check_hit(back *back, map *mp, trap *tr);
void display_menu(menu *menu, back *back, sfEvent event);
void get_menu(menu *menu);
void manage_mouse_click(menu **menu, back **back, trap **trap, map **mp);
void display_win(menu *menu, back *back, sfEvent event);
void display_loose(menu *menu, back *back, sfEvent event);
void analyse_event(back *back, map *map, menu *menu, trap *trap);
void first_menu(back *back, map *mp, menu *menu, trap *tr);
void show_defeat(back *back, map *map, menu *menu);
void call_destroy(menu *menu);
