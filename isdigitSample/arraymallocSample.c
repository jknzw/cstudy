#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "define.h"

// ���I��������malloc�̃T���v��
int arrayMallocSample()
{
    //char��������g�p����infname�̒��Ƀt�@�C���p�X����
    char infname[] = IN_FILE_PATH;

    //char��������g�p����outfname�̒��Ƀt�@�C���p�X����
    char outfname[] = OUT_FILE_PATH;

    // ���I�Ƀ��������m��
    char* str;
    str = (char*)malloc(sizeof(char) * MAX_LEN);
    if (str == NULL)
    {
        // �������m�ێ��s
        return -1;
    }

    // ������
    memset(str, '\0', sizeof(char) * MAX_LEN);

    // �f�[�^��ݒ�
    strcpy(str, "test data");

    // �o��
    printf("%s\n", str);

    // ���
    free(str);

    return SUCCESS;
}