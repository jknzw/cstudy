#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "sample.h"

// �t�@�C���Ǎ��֐�
int filereadSample(char* pInFilePath)
{
    int ret = 0;

    // �t�@�C���|�C���^�̏�����
    FILE* fp;

    // �Ǎ��݃��[�h�ur�v�Ńt�@�C�����J���B
    // �t�@�C���������ꍇ�̓G���[
    // VisualStudio�ł̃f�o�b�O���s���̑��΃p�X��exe�𒼐ڎ��s�������ƈႢ�A
    // �\�[�X�t�@�C���Acvxproj�Ɠ����K�w�ɂȂ邽�ߒ���
    // === �Z�L�����e�B�����Ŋ֐��ɂ��� === 
    // C99(1999�N)��C����ł�fopen���W�����������A
    // C11(2011�N)�ȍ~��C����ł�fopen_s��W���Ƃ��Ă���B
    // _s����������Ă���֐���_s���g���悤�ɁB
    // �Q�l https://docs.microsoft.com/ja-jp/cpp/c-runtime-library/security-features-in-the-crt?view=vs-2019
    errno_t errCode = fopen_s(&fp, pInFilePath, "r");
    if (0 != errCode)
    {
        // �t�@�C���Ǎ��G���[
        ret = errCode;
    }
    else if (fp == NULL)
    {
        ret = -99;
    }

    if (0 == ret)
    {
        // �t�@�C���I�[�v���ɐ��������ꍇ
        // EOF�܂œǂݍ���
        int idx = 0;

        // �������{�錾
        char line[MAX_TEXT_SIZE] = { '\0' };
        // memset�ŏ��������鎖���ł���
        // memset(line, '\0', sizeof(line));

        while (NULL != fgets(line, sizeof(line), fp))
        {
            idx++;
            printf("[%d]%s", idx, line);
        }

        // �t�@�C���͕K������
        fclose(fp);
    }

    return ret;
}

// �ǂݍ��񂾃f�[�^��񎟌��z��Ɋi�[����
// https://tondol.hatenablog.jp/entry/20090713/1247426321
int filereadSample2(char* pInFilePath)
{
    int ret = 0;

    FILE* fp;

    // �Ǎ��݃��[�h�ur�v�Ńt�@�C�����J���B
    errno_t errCode = fopen_s(&fp, pInFilePath, "r");
    if (0 != errCode)
    {
        // �t�@�C���Ǎ��G���[
        ret = errCode;
    }
    else if (fp == NULL)
    {
        ret = -99;
    }

    // char*�̃A�h���X��ێ�����̈���m��
    char** textArr = malloc(sizeof(char*) * MAX_LINE * MAX_TEXT_SIZE);
    if (NULL == textArr)
    {
        // �������m�ێ��s���̓G���[
        printf("�A�h���X�̃������m�ۂɎ��s");
        return -1;
    }

    // char�z���ێ�����̈���m��
    char* line = malloc(sizeof(char) * MAX_LINE * MAX_TEXT_SIZE);
    if (line == NULL)
    {
        // �������m�ێ��s���̓G���[
        printf("���Ԃ̃������m�ۂɎ��s");
        return -2;
    }

    // memset�ŏ�����
    memset(line, '\0', sizeof(char) * MAX_LINE * MAX_TEXT_SIZE);

    for (int i = 0; i < MAX_LINE; i++)
    {
        // �e�v�f�̐擪�A�h���X��ݒ�
        textArr[i] = line + (__int64)i * MAX_TEXT_SIZE;
    }

    int readCount = 0;
    if (0 == ret)
    {
        // �t�@�C���I�[�v���ɐ��������ꍇ
        // EOF�܂œǂݍ���
        while (0 == feof(fp))
        {
            // 1�s�ǂݍ���
            char text[MAX_TEXT_SIZE] = { '\0' };
            fgets(text, MAX_TEXT_SIZE, fp);

            printf("[%d]%s", readCount, text);

            // �z��Ɋi�[
            strcpy_s(textArr[readCount], MAX_TEXT_SIZE, text);

            readCount++;
        }

        // ���s
        printf("\r\n");

        // �t�@�C���͕K������
        fclose(fp);
    }

    // �s�v�ɂȂ����烁�������������
    // �z��̒��g���ɉ������
    free(line);
    free(textArr);

    return ret;
}

