// WARNING C4996 �}�~
// https://docs.microsoft.com/ja-jp/cpp/error-messages/compiler-warnings/compiler-warning-level-3-c4996?view=vs-2019
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

// include
// �W�����C�u������ <> ��
// ����w�b�_�� "" �ň͂�
#include <stdio.h>
#include "define.h"
#include "struct.h"
#include "extern.h"

// �t�@�C���Ǎ��֐�
//   �֐�������ptrPersonList�����������邽�߁ALIST_PERSON�̃|�C���^�̃A�h���X�������ɐݒ肷�邱�Ɓi�|�C���^�̃|�C���^�j
// filePath      : �t�@�C���p�X
// ptrPersonList : LIST_PERSON�̃|�C���^�̃|�C���^
// return        : �ǂݍ��ݍs��
int readInputFile(const char* filePath, LIST_PERSON** ptrPersonList)
{
    // �t�@�C���I�[�v��
    FILE* fp = fopen(filePath, "r");

    // �t�@�C�����I�[�v���ł������`�F�b�N
    if (fp == NULL) {
        //�t�@�C���������ꍇ�G���[
        printf("%s�����݂��܂���B", filePath);
        return IN_FILE_OPEN_ERROR;
    }

    // csv�f�[�^��ǂݍ��ݔz��Ɋi�[
    int dataCount = 0;
    while (1) {

        // �\���̂̕ϐ���錾��0�ŏ�����
        PERSON person = { 0 };

        // �t�@�C������1�s�ǂݍ��ݍ\���̂Ɋi�[����
        // ID,����,Lv,HP,MP,ATK,DEF,SPD
        if (fscanf(fp, "%d,%[^,],%d,%d,%d,%d,%d,%d\n"
            , &person.id
            , person.name
            , &person.lv
            , &person.hp
            , &person.mp
            , &person.atk
            , &person.def
            , &person.spd) == 8)
        {
            // �ǂݍ��񂾐�������ȏꍇ
            printf("%d,%s,%d,%d,%d,%d,%d,%d\n"
                , person.id
                , person.name
                , person.lv
                , person.hp
                , person.mp
                , person.atk
                , person.def
                , person.spd);
            dataCount++;
        }
        else {
            // �t�@�C���̖����܂��̓t�H�[�}�b�g�ُ�̏ꍇ
            // ����ɓǂݍ��߂Ȃ������ꍇ�͓Ǎ������𔲂���
            printf("break\n");
            break;
        }

        // LIST_PERSON�ɒǉ�����
        add(ptrPersonList, person);
    }

    // �t�@�C�������
    fclose(fp);

    // �ǂݍ��񂾍s����ԋp
    return dataCount;
}
