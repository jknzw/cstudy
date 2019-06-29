#pragma once
#include "define.h"

//�\���̐錾
//ID, ����, Lv, HP, MP, ATK, DEF, SPD
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

// ���X�g�p�\����
typedef struct listperson {
    struct listperson* next;
    PERSON person;
} LIST_PERSON;
