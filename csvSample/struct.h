#pragma once
#include "define.h"

//\‘¢‘ÌéŒ¾
//ID, –¼Ì, Lv, HP, MP, ATK, DEF, SPD
typedef struct person {
    int id;
    char name[TEXT_MAX_LENGTH];
    int lv;
    int hp;
    int mp;
    int atk;
    int def;
    int spd;
} PERSON;
