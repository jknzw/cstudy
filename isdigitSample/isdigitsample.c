#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "define.h"

/*** IN_FILE �T���v���f�[�^ ***
2
10
6
008
1a5
8

4
13A
b40
******************************/

// �֐��̃v���g�^�C�v�錾
int sample1(int argc, char* argv[]);
int sample2(int argc, char* argv[]);
bool isstrdigit(char* str);

// ���C��
int main(int argc, char* argv[])
{
    char str[MAX_LEN] = { '\0' };

    printf("�������֐���I�����ĉ������B\n");
    printf("1:sample1 ������̐��l����T���v��\n");
    printf("2:sample2 ������̐��l������֐��������T���v��\n");
    printf(">");

    // �W�����͂���ǂݍ���
    while (fgets(str, sizeof(str), stdin) != NULL) {
        bool endflg = false;
        int ret = -1;

        // ���͂̐��l�������擾 (\n �� 0 / 1\n �� 1)
        int mode = atoi(str);
        switch (mode)
        {
        case 1:
            ret = sample1(argc, argv);
            if (ret != 0)
            {
                // �G���[�I��
                return ret;
            }
            break;
        case 2:
            ret = sample2(argc, argv);
            if (ret != 0)
            {
                // �G���[�I��
                return ret;
            }
            break;
        default:
            endflg = true;
            break;
        }

        // while���[�v���甲���鏈��
        if (endflg)
        {
            break;
        }
        else
        {
            // next loop
            printf("�������֐���I�����ĉ������B\n");
            printf("1:sample1 ������̐��l����T���v��\n");
            printf("2:sample2 ������̐��l������֐��������T���v��\n");
            printf(">");
        }
    }

    return SUCCESS;
}

// ���l����T���v��
int sample1(int argc, char* argv[])
{
    //���̓t�@�C���|�C���^�^�̒�`
    FILE* infp;

    //�o�̓t�@�C���|�C���^�̒�`
    FILE* outfp;

    //char��������g�p����infname�̒��Ƀt�@�C���p�X����
    char infname[] = IN_FILE_PATH;

    //char��������g�p����outfname�̒��Ƀt�@�C���p�X����
    char outfname[] = OUT_FILE_PATH;

    char str[MAX_LEN] = { '\0' };
    char inText[MAX_LINE][MAX_LEN] = { '\0' };

    //infp = ���̓t�@�C���I�[�v��(�t�@�C����Ǎ����[�h�ŊJ��)
    infp = fopen(infname, "r");

    //���̓t�@�C���|�C���^�Ƀt�@�C���������ꍇNULL��Ԃ�
    if (infp == NULL) {
        //���̓t�@�C�����J���Ȃ��G���[�\��
        printf("���̓t�@�C�������݂��܂���\n");
        //�G���[�����̏ꍇ-1��Ԃ�
        return IN_FILE_OPEN_ERROR;
    }

    int count = 0;
    // �yC�������z�t�@�C���̓ǂݍ��ݕ��@�܂Ƃ�(fopen, fgets)
    // https://www.sejuku.net/blog/24615
    while (fgets(str, sizeof(str), infp) != NULL) {
        printf("=== ������ 1�s�ǂݍ��ݏ��� ������ ===\n");

        // fgets�͉��s���ǂݍ��ނ��߁A���s���폜
        // strlen�͖�����\0�܂ł̒��������߂�
        int len = strlen(str);
        if (str[len - 1] == '\n')
        {
            str[len - 1] = '\0';
        }

        printf("�ǂݍ��񂾕�����:[%s]\n", str);

        if (str[0] == '\0')
        {
            // ��s�̏ꍇ�ǂݔ�΂�
            continue;
        }

        // �z��Ɋi�[
        strcpy(inText[count], str);
        count++;

        // ������ ���l���菈�� ������
        // �������݂̂̔���B�����𔻒肷��ꍇ�͕ʓr�����_�̈ʒu�␔�𔻒肵�Ȃ��Ƃ����Ȃ�
        printf("=== ������ ���l���胋�[�v ������ ===\n");
        bool isNum = true;
        for (int i = 0; i < (int)strlen(str); i++)
        {
            if (isdigit(str[i])) {
                // ���l
                printf("[%d][%c]�͐��l\n", i, str[i]);
            }
            else
            {
                // ���l�ȊO�̕���
                printf("[%d][%c]�͐��l�ȊO\n", i, str[i]);
                isNum = false;

                // ���l�ȊO�̕���������������𔲂���
                break;
            }
        }
        printf("=== ������ ���l���胋�[�v ������ ===\n");

        // ����
        if (isNum)
        {
            printf("[%s]�͐��l\n", str);
        }
        else
        {
            printf("[%s]�͐��l�ȊO\n", str);
        }
        // ������ ���l���菈�� ������

        printf("=== ������ 1�s�ǂݍ��ݏ��� ������ ===\n");
    }

    //outfp = �o�̓t�@�C���I�[�v��(�t�@�C�����������݃��[�h�ŊJ��)
    outfp = fopen(outfname, "w");

    //�o�̓t�@�C���|�C���^�Ƀt�@�C���������ꍇNULL��Ԃ�
    if (outfp == NULL) {
        //�o�̓t�@�C�����J���Ȃ��G���[�\��
        printf("�o�̓t�@�C�������݂��܂���\n");
        //���̓t�@�C�������
        fclose(infp);
        //�G���[�����̏ꍇ-2��Ԃ�
        return OUT_FILE_OPEN_ERROR;
    }

    printf("=== ������ �o�͏��� ������ ===\n");

    // sizeof(inText) / sizeof(inText[i])
    // �񎟌��z��S�̂̃T�C�Y��z��1�s�̃T�C�Y�Ŋ����ė�̃T�C�Y�����߂�
    for (int i = 0; i < sizeof(inText) / sizeof(inText[i]); i++)
    {
        printf("�o�͕�����[%s]\n", inText[i]);
        if (strlen(inText[i]) == 0)
        {
            // ��v�f����������o�͂����ɔ�����
            break;
        }

        // ������ ���l���菈��2 ������
        // �������݂̂̔���B�����𔻒肷��ꍇ�͕ʓr�����_�̈ʒu�␔�𔻒肵�Ȃ��Ƃ����Ȃ�
        printf("=== ������ ���l���胋�[�v2 ������ ===\n");
        bool isNum = true;
        for (int j = 0; j < (int)strlen(inText[i]); j++)
        {
            if (isdigit(inText[i][j])) {
                // ���l
                printf("[%d][%d][%c]�͐��l\n", i, j, inText[i][j]);
            }
            else
            {
                // ���l�ȊO�̕���
                printf("[%d][%d][%c]�͐��l�ȊO\n", i, j, inText[i][j]);
                isNum = false;

                // ���l�ȊO�̕���������������𔲂���
                break;
            }
        }
        printf("=== ������ ���l���胋�[�v2 ������ ===\n");

        // ����
        if (isNum)
        {
            printf("[%s]�͐��l\n", inText[i]);
        }
        else
        {
            printf("[%s]�͐��l�ȊO\n", inText[i]);
        }
        // ������ ���l���菈��2 ������

        fprintf(outfp, "%s\n", inText[i]);
    }

    printf("=== ������ �o�͏��� ������ ===\n");


    //�t�@�C�������
    fclose(infp);
    fclose(outfp);

    return SUCCESS;
}

// ������̐��l������֐��������T���v��
int sample2(int argc, char* argv[])
{
    //���̓t�@�C���|�C���^�^�̒�`
    FILE* infp;

    //�o�̓t�@�C���|�C���^�̒�`
    FILE* outfp;

    //char��������g�p����infname�̒��Ƀt�@�C���p�X����
    char infname[] = IN_FILE_PATH;

    //char��������g�p����outfname�̒��Ƀt�@�C���p�X����
    char outfname[] = OUT_FILE_PATH;

    char str[MAX_LEN] = { '\0' };
    char inText[MAX_LINE][MAX_LEN] = { '\0' };

    //infp = ���̓t�@�C���I�[�v��(�t�@�C����Ǎ����[�h�ŊJ��)
    infp = fopen(infname, "r");

    //���̓t�@�C���|�C���^�Ƀt�@�C���������ꍇNULL��Ԃ�
    if (infp == NULL) {
        //���̓t�@�C�����J���Ȃ��G���[�\��
        printf("���̓t�@�C�������݂��܂���\n");
        //�G���[�����̏ꍇ-1��Ԃ�
        return IN_FILE_OPEN_ERROR;
    }

    int count = 0;
    // �yC�������z�t�@�C���̓ǂݍ��ݕ��@�܂Ƃ�(fopen, fgets)
    // https://www.sejuku.net/blog/24615
    while (fgets(str, sizeof(str), infp) != NULL) {
        printf("=== ������ 1�s�ǂݍ��ݏ��� ������ ===\n");

        // fgets�͉��s���ǂݍ��ނ��߁A���s���폜
        // strlen�͖�����\0�܂ł̒��������߂�
        int len = strlen(str);
        if (str[len - 1] == '\n')
        {
            str[len - 1] = '\0';
        }

        printf("�ǂݍ��񂾕�����:[%s]\n", str);

        if (str[0] == '\0')
        {
            // ��s�̏ꍇ�ǂݔ�΂�
            continue;
        }

        // �z��Ɋi�[
        strcpy(inText[count], str);
        count++;

        // ������ ���l���菈�� ������
        if (isstrdigit(str))
        {
            printf("[%s]�͐��l\n", str);
        }
        else
        {
            printf("[%s]�͐��l�ȊO\n", str);
        }
        // ������ ���l���菈�� ������

        printf("=== ������ 1�s�ǂݍ��ݏ��� ������ ===\n");
    }

    //outfp = �o�̓t�@�C���I�[�v��(�t�@�C�����������݃��[�h�ŊJ��)
    outfp = fopen(outfname, "w");

    //�o�̓t�@�C���|�C���^�Ƀt�@�C���������ꍇNULL��Ԃ�
    if (outfp == NULL) {
        //�o�̓t�@�C�����J���Ȃ��G���[�\��
        printf("�o�̓t�@�C�������݂��܂���\n");
        //���̓t�@�C�������
        fclose(infp);
        //�G���[�����̏ꍇ-2��Ԃ�
        return OUT_FILE_OPEN_ERROR;
    }

    printf("=== ������ �o�͏��� ������ ===\n");

    // sizeof(inText) / sizeof(inText[i])
    // �񎟌��z��S�̂̃T�C�Y��z��1�s�̃T�C�Y�Ŋ����ė�̃T�C�Y�����߂�
    for (int i = 0; i < sizeof(inText) / sizeof(inText[i]); i++)
    {
        printf("�o�͕�����[%s]\n", inText[i]);
        if (strlen(inText[i]) == 0)
        {
            // ��v�f����������o�͂����ɔ�����
            break;
        }

        // ������ ���l���菈��2 ������
        if (isstrdigit(inText[i]))
        {
            printf("[%s]�͐��l\n", inText[i]);
        }
        else
        {
            printf("[%s]�͐��l�ȊO\n", inText[i]);
        }
        // ������ ���l���菈��2 ������

        fprintf(outfp, "%s\n", inText[i]);
    }

    printf("=== ������ �o�͏��� ������ ===\n");


    //�t�@�C�������
    fclose(infp);
    fclose(outfp);

    return SUCCESS;
}

// ������̐��l����֐��T���v��
bool isstrdigit(char* str)
{
    // �������݂̂̔���B�����𔻒肷��ꍇ�͕ʓr�����_�̈ʒu�␔�𔻒肵�Ȃ��Ƃ����Ȃ�
    printf("=== ������ ���l���胋�[�v ������ ===\n");
    bool isNum = true;

    // strlen��\0�܂ł̕��������擾����
    for (int i = 0; i < (int)strlen(str); i++)
    {
        if (isdigit(str[i])) {
            // ���l
            printf("[%d][%c]�͐��l\n", i, str[i]);
        }
        else
        {
            // ���l�ȊO�̕���
            printf("[%d][%c]�͐��l�ȊO\n", i, str[i]);
            isNum = false;

            // ���l�ȊO�̕���������������𔲂���
            break;
        }
    }
    printf("=== ������ ���l���胋�[�v ������ ===\n");
    return isNum;
}
