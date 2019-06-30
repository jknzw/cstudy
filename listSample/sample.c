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

// �萔��`
// �t�@�C���p�X��`
#define IN_FILE_PATH "C:\\work\\input.csv"
#define OUT_FILE_PATH "C:\\work\\out.txt"

// include
// �W�����C�u������ <> ��
// ����w�b�_�� "" �ň͂�
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "define.h"
#include "extern.h"

// ���C��
int main(int argc, char* argv[])
{
    // �t�@�C������ǂݎ���p�̕ϐ��Ő錾����
    const char* inFile = IN_FILE_PATH;
    const char* outFile = OUT_FILE_PATH;

    // List�ϐ���NULL�Œ�`
    LIST_PERSON* listp = NULL;

    printf("������ IN�t�@�C���Ǎ� ������\n");
    // �t�@�C������f�[�^��ǂݍ���
    int inDataCount = readInputFile(inFile, &listp);

    // �ǂݍ��񂾌������`�F�b�N
    if (inDataCount < 0)
    {
        // �t�@�C���̓ǂݍ��݂Ɏ��s
        printf("�t�@�C���̓ǂݍ��݂Ɏ��s���܂����B\n");

        // ���������
        release(&listp);

        // �G���[�I��
        return inDataCount;
    }
    printf("������ IN�t�@�C���Ǎ� ������\n");

    printf("������ �f�[�^�o�͏��� ������\n");
    // �o�̓t�@�C���I�[�v��
    FILE* outfp = fopen(outFile, "w");

    // �o�̓t�@�C���I�[�v���G���[�`�F�b�N
    if (outfp == NULL) {
        // �o�̓t�@�C�����J���Ȃ������ꍇ
        printf("�o�̓t�@�C���̍쐬�Ɏ��s���܂����B\n");
        
        // ���������
        release(&listp);

        // �G���[�I��
        return OUT_FILE_OPEN_ERROR;
    }

    // LIST_PERSON����f�[�^�����o���o��
    for (LIST_PERSON* now = listp; now != NULL; now = now->next)
    {
        // �R���\�[���o��
        // printf�ł͂Ȃ��Afprintf���g�����@������
        fprintf(stdout, "--- %d ---\n", now->person.id);
        fprintf(stdout, "%s\n", now->person.name);
        fprintf(stdout, "HP %d\n", now->person.hp);
        fprintf(stdout, "MP %d\n", now->person.mp);

        // �t�@�C���o��
        fprintf(outfp, "--- %d ---\n", now->person.id);
        fprintf(outfp, "%s\n", now->person.name);
        fprintf(outfp, "HP %d\n", now->person.hp);
        fprintf(outfp, "MP %d\n", now->person.mp);
    }

    fclose(outfp);
    printf("������ �f�[�^�o�͏��� ������\n");

    // ���������
    release(&listp);
    return SUCCESS;
}
