/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** runner csfml game
*/
#include "include/my.h"

void init_struct4(back back, map map, trap tr, menu menu)
{
    tr.char_clock = sfClock_create();
    tr.trap_speed = 3;
    tr.trap_clock = sfClock_create();
    tr.text_trapb = sfTexture_createFromFile("trap.png", NULL);
    tr.rect_trapb.left = 233;
    tr.rect_trapb.top = 595;
    tr.rect_trapb.width = 55;
    tr.rect_trapb.height = 70;
    tr.position_trap.x = -100;
    tr.position_trap.y = 415;
    tr.position_trapt.x = -100;
    tr.position_trapt.y = 353;
    tr.position_traprem.x = 1240;
    tr.position_traprem.y = 460;
    tr.ttr = sfSprite_create();
    tr.btr = sfSprite_create();
    tr.life = 3;
    sfSprite_setPosition(tr.ttr, tr.position_trapt);
    sfSprite_setPosition(tr.btr, tr.position_trap);
    launch_game(back, map, tr, menu);
}

void init_struct3(back back, map map, trap tr, menu menu)
{
    map.uni = sfSprite_create();
    map.text_uni = sfTexture_createFromFile("Unicorn.png", NULL);
    map.uni_clock = sfClock_create();
    map.rect_uni.left = 605;
    map.rect_uni.top = 330;
    map.rect_uni.width = 220;
    map.rect_uni.height = 110;
    map.position_uni.x = -20;
    map.position_uni.y = 390;
    map.offset = -1;
    map.text = sfText_create();
    map.display_score = sfText_create();
    map.fontext = sfFont_createFromFile("arial.ttf");
    map.score = 0;
    sfText_setFont(map.text, map.fontext);
    sfText_setFont(map.display_score, map.fontext);
    sfText_setCharacterSize(map.display_score, 20);
    sfText_setCharacterSize(map.text, 20);
    init_struct4(back, map, tr, menu);
}

void read_map(back back, char **av)
{
    struct map map;
    struct stat op;
    struct trap tr;
    struct menu menu;
    int fd;

    stat(av[1], &op);
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        exit(84);
    map.mp = malloc(sizeof(char) + op.st_size);
    read(fd, map.mp, op.st_size);
    map.mp[op.st_size + 1] = '\0';
    map.i = 0;
    map.pos_text.x = 20;
    map.pos_text.y = 20;
    map.pos_score.y = 20;
    map.pos_score.x = 90;
    map.jump = 0;
    init_struct3(back, map, tr, menu);
}

void init_struct2(back back, char **av)
{
    back.position_text.x = 0;
    back.position_text.y = 0;
    back.position_text2.x = 0;
    back.position_text2.y = 0;
    back.position_text3.x = 0;
    back.position_text3.y = 0;
    back.position_text4.x = 0;
    back.position_text4.y = 0;
    back.position_text_sec2.x = 1270;
    back.position_text_sec2.y = 0;
    back.position_text_sec3.x = 1270;
    back.position_text_sec3.y = 0;
    back.position_text_sec4.x = 1270;
    back.position_text_sec4.y = 0;
    back.position_ground.x = 0;
    back.position_ground.y = 480;
    back.position_ground2.x = 1200;
    back.position_ground2.y = 480;
    read_map(back, av);
}

void init_struct(back back, char **av)
{
    sfVideoMode mode = {1200, 530, 32};

    back.sprite_ground = sfSprite_create();
    back.sprite = sfSprite_create();
    back.sprite2 = sfSprite_create();
    back.sprite3 = sfSprite_create();
    back.sprite4 = sfSprite_create();
    back.sprite_sec = sfSprite_create();
    back.sprite_sec2 = sfSprite_create();
    back.sprite_sec3 = sfSprite_create();
    back.sprite_sec4 = sfSprite_create();
    back.sprite_gr_sec = sfSprite_create();
    back.window = sfRenderWindow_create(mode, "Pony run", sfDefaultStyle, NULL);
    back.texture = sfTexture_createFromFile("Background4.png", NULL);
    back.texture_ground = sfTexture_createFromFile("ground.png", NULL);
    back.texture2 = sfTexture_createFromFile("Background3.png", NULL);
    back.texture3 = sfTexture_createFromFile("Background2.png", NULL);
    back.texture4 = sfTexture_createFromFile("Background1.png", NULL);
    back.text_clock = sfClock_create();
    init_struct2(back, av);
}
