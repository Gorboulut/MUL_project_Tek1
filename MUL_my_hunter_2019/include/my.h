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
#define EXIT_USAGE    84

typedef struct framebuffer {
    sfSprite *sprite;
    sfTexture *texture;
    sfTexture *font;
    sfSprite *back;
    sfRenderWindow *window;
    sfIntRect rect;
    int offset;
    sfClock *spr_clock;
    sfVector2f position_duck;
    float speed;
    float seconds;
    float spr_mv;
    sfTime time_spr;
    int score;
    sfFont *fontext;
    sfText *text;
    int life;
    sfText *life_text;
    sfText *display_life;
    sfText *display_score;
    sfVector2f pos_text;
    sfVector2f pos_life;
    int menu_nbr;
    sfTexture *menu_texture;
    sfSprite *menu;
    sfMusic *music;
    sfMusic *music2;
    sfSprite *sp_c;
    sfTexture *text_c;
    sfSprite *end_spr;
    sfTexture *end_text;
    sfVector2i c;
} framebuffer_t;

void my_putchar(char c);
char *my_strcat(char *dest, char const *src);
int my_strlen(char const *str);
int my_compute_power_rec(int nb, int p);
int my_put_nbr(int nb);
int copy_fac(int nb, int negative, int big, int border);
void copy_fac2(int nb, int factor, int border, int big);
void display (int nb, int border, int big, int cpy_nb);
int my_strcmp(char const *s1, char const *s2);
char *my_strlowcase(char *str);
int my_putstr(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_compute_square_root(int nb);
char *my_revstr(char *str);
int my_str_isalpha(char const *str);
int my_strncmp(char const *s1, char const *s2, int n);
int my_find_prime_sup(int nb);
int more_than_ten(int nb);
int check_simple_nbr(int nb);
int my_str_islower(char const *str);
char *my_strncpy(char *dest, char const *src, int n);
void sign(char const *str, int x);
int write_nbr(char const *str, int x, int stop_nbr);
int funct_call(char const *str, int x, int stop_sign);
int my_getnbr(char const *str);
int my_atoi(char *str);
int my_showstr(char const *str);
int my_str_isnum(char const *str);
char *my_strstr(char *str, char const *to_find);
int my_isneg(int n);
int my_str_isprintable(char const *str);
char *my_strupcase(char *str);
int is_prime(int nb);
int more_ten(int nb);
int my_is_prime(int nb);
char *my_strcapitalize(char *str);
int my_str_isupper(char const *str);
void my_swap(int *a, int *b);
char *concat_params(int argc, char **argv);
int my_show_word_array(char * const *tab);
char *my_strdup(char const *src);
char **change_tab(char *conv, char **tab, int w, int x);
int my_isnotalpha(char const *str, int y);
char **my_str_to_word_array(char const *str);
char *suppr_space(char *str);
char *str_update(char *num_chg, char *str, int i, char *num_final);
char *nbr_change(char *str, char *num_chg);
char *op_change(char *str, char *str_chg);
char *back_op(char *str, char *num_chg, char *str_final);
int my_print_help(void);
char *double_lowprio(char *s);
char *low_prio(char *str);
char *get_secstr(char *str, int i);
char *get_firststr(char *str, int i);
char *my_add(char *str, int i, int k);
int remember(char *result, int y);
char *adapt_str2(char *str, int i, int car, char c);
char *adapt_str(char *change, char *str, int i, char c);
char *my_sub(char *str, int i);
char *suppr_O(char *result);
char *adapt_sub_str(char *result, int w);
char *my_div(char *str, int count);
char *divinf(char *first, char *sec);
char *add(char *first_nbr, char *sec_nbr);
char *sub_left(char *first_nbr, char *sec_nbr);
int bigger_number(char *first, char *sec, char c);
char *high_prio(char *str);
void print_str(char *str);
char *adapt_str_par(char *nbr, char *str, int i);
char *final_cut_str(char *str);
int my_number(char *str);
int total_size(char *str);
int error_detect(char *str, int i);
char **find_square(char **tab, int col, int lenght);
int my_number(char *str);
char *my_conv_tab(char *str);
int my_strlenght(char *str);
char *my_realloc(char *str, char *fullstr, int len);
void tab_back(char **tab, int col, int lenght);
void call_func(char **av);
int bsq(char *extend, int col, int lenght);
int single_lign(char *extend, int i);
void get_backg(struct framebuffer op);
void duck_sprite(struct framebuffer op);
void call_hunt(struct framebuffer op);
void init_struc1(struct framebuffer op);
char *itoa(int n);
void check_life(struct framebuffer *op, sfEvent event);
void display_help(void);
void call_menu(struct framebuffer op, sfEvent event);
void manage_mouse_click(struct framebuffer **op);
void move_rect(struct framebuffer *op);
void set_text(struct framebuffer op);
void analyse_events(struct framebuffer *op, sfEvent event);
void cursor_sprite(struct framebuffer *op);
void sprite_mov(struct framebuffer *op);
