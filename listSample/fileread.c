#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include "define.h"
#include "struct.h"
#include "extern.h"

#define LINE_MAX 256

// �t�@�C���̍s�����擾����
int getFileLineCount(const char* filePath)
{
    int count = 0;

    FILE* fp = fopen(filePath, "r");

    if (fp == NULL) {
        printf("%s�����݂��܂���B", filePath);
        return IN_FILE_OPEN_ERROR;
    }

    // �t�@�C����ǂݍ��ݍs�����擾
    char buf[LINE_MAX] = { '\0' };
    while (fgets(buf, sizeof(buf), fp) != NULL)
    {
        count++;
    }

    fclose(fp);

    // �ǂݍ��񂾍s����ԋp
    return count;
}

// �t�@�C���Ǎ�
int readInputFile(const char* filePath, LIST_PERSON** arrPerson)
{
    //�t�@�C���I�[�v��
    FILE* fp = fopen(filePath, "r");

    if (fp == NULL) {
        //�t�@�C���������ꍇ
        printf("%s�����݂��܂���B", filePath);
        return IN_FILE_OPEN_ERROR;
    }

    // csv�f�[�^��ǂݍ��ݔz��Ɋi�[
    int dataCount = 0;
    while (1) {
        PERSON person = { 0 };

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
            //��L�ȊO�͓Ǎ������𔲂���
            printf("break\n");
            break;
        }

        add(arrPerson, person);
    }

    fclose(fp);

    // �ǂݍ��񂾍s����ԋp
    return dataCount;
}
