#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

// �t�@�C������f�[�^��ǂݍ��݁A
// ���H���ďo�͂���v���O�����̃T���v��

/* input.csv ID,����,Lv,HP,MP,ATK,DEF,SPD
1,�R�c,20,120,0,100,50,10
2,���,22,100,20,80,55,12
3,����,18,80,50,30,40,8
*/

/* out.txt
--- 1 ---
�R�c
HP 120
MP 0
--- 2 ---
���
HP 100
MP 20
--- 3 ---
����
HP 80
MP 50
*/

// �t�@�C���p�X��`
#define IN_FILE_PATH "C:\\work\\input.csv"
#define OUT_FILE_PATH "C:\\work\\out.txt"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "define.h"
#include "extern.h"

int main(int argc, char* argv[])
{
    // �t�@�C������ǂݎ���p�̕ϐ��Ő錾����
    const char* inFile = IN_FILE_PATH;

    printf("������ IN�t�@�C���Ǎ� ������\n");
    // �t�@�C���̌������擾
    int inFileCount = getFileLineCount(inFile);
    if (inFileCount < 0)
    {
        return inFileCount;
    }

    //�\���̂̃|�C���^��錾���A�������𓮓I�Ɋm��
    int personSize = sizeof(PERSON) * inFileCount;
    PERSON* person = (PERSON*)malloc(personSize);
    if (person == NULL)
    {
        // malloc�Ɏ��s
        return MALLOC_ERROR;
    }
    memset(person, 0x00, personSize);

    // �t�@�C������f�[�^��ǂݍ���
    int inDataCount = readInputFile(inFile, person, inFileCount);
    if (inDataCount < 0)
    {
        // �t�@�C���̓ǂݍ��݂Ɏ��s
        free(person);
        return inDataCount;
    }
    printf("������ IN�t�@�C���Ǎ� ������\n");

    printf("������ �f�[�^�o�͏��� ������\n");
    //�o�̓t�@�C���I�[�v��
    FILE* outfp = fopen(OUT_FILE_PATH, "w");
    if (outfp == NULL) {
        printf("�o�̓t�@�C���̍쐬�Ɏ��s���܂����B\n");
        return OUT_FILE_OPEN_ERROR;
    }

    for (int i = 0; i < inDataCount; i++)
    {
        // �R���\�[���o��
        // printf�ł͂Ȃ��Afprintf���g�����@������
        fprintf(stdout, "--- %d ---\n", (person + i)->id);
        fprintf(stdout, "%s\n", (person + i)->name);
        fprintf(stdout, "HP %d\n", (person + i)->hp);
        fprintf(stdout, "MP %d\n", (person + i)->mp);

        // �t�@�C���o��
        fprintf(outfp, "--- %d ---\n", (person + i)->id);
        fprintf(outfp, "%s\n", (person + i)->name);
        fprintf(outfp, "HP %d\n", (person + i)->hp);
        fprintf(outfp, "MP %d\n", (person + i)->mp);
    }

    fclose(outfp);
    printf("������ �f�[�^�o�͏��� ������\n");

    free(person);
    return SUCCESS;
}
