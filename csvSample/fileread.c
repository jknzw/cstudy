#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include "define.h"
#include "struct.h"

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
int readInputFile(const char* filePath, PERSON* arrPerson, int maxSize)
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
    for (int i = 0; i < maxSize; i++) {
        // ID,����,Lv,HP,MP,ATK,DEF,SPD
        if (fscanf(fp, "%d,%[^,],%d,%d,%d,%d,%d,%d\n"
            , &(arrPerson + i)->id
            , (arrPerson + i)->name
            , &(arrPerson + i)->lv
            , &(arrPerson + i)->hp
            , &(arrPerson + i)->mp
            , &(arrPerson + i)->atk
            , &(arrPerson + i)->def
            , &(arrPerson + i)->spd) == 8)
        {
            // �ǂݍ��񂾐�������ȏꍇ
            dataCount++;
        }
        else {
            //��L�ȊO�͓Ǎ������𔲂���
            break;
        }
    }

    fclose(fp);

    // �ǂݍ��񂾍s����ԋp
    return dataCount;
}
