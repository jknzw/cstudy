#pragma once
#include "define.h"

//構造体宣言
//ID, 名称, Lv, HP, MP, ATK, DEF, SPD
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

// リスト用構造体
typedef struct listperson {
    struct listperson* next;
    PERSON person;
} LIST_PERSON;
