#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h> // malloc

#define GENDER_MAN 0
#define GENDER_WOMAN 1

typedef struct _HUMAN {
    int id;
    char name[64];
    int age;
    int gender;
} HUMAN;

int structsample()
{
    // �\���̂̔z��̐錾
    HUMAN shain[20] = { 0 };

    // �l��ݒ�
    shain[0].id = 0;
    strcpy(shain[0].name, "�R�c");
    shain[0].age = 20;
    shain[0].gender = GENDER_MAN;

    // �\���̂̃|�C���^�̐錾
    HUMAN* pShain;
    // �\���̂̔z��̐擪�̃A�h���X��ݒ�
    pShain = shain;

    // index��0����1�Ɉړ�(�|�C���^�̃A�h���X���ړ�)
    pShain++;

    // �l��ݒ�
    pShain->id = 1;
    strcpy(pShain->name, "����");
    pShain->age = 25;
    pShain->gender = GENDER_WOMAN;

    // �o��
    printf("�o�͇@[%d][%s][%d][%d]\n", shain[0].id, shain[0].name, shain[0].age, shain[0].gender);
    printf("�o�͇A[%d][%s][%d][%d]\n", shain[1].id, shain[1].name, shain[1].age, shain[1].gender);

    // �A�h���X��擪�ɖ߂�
    pShain = shain;

    // �o��
    printf("�o�͇B[%d][%s][%d][%d]\n", pShain->id, pShain->name, pShain->age, pShain->gender);
    pShain++;
    printf("�o�͇C[%d][%s][%d][%d]\n", pShain->id, pShain->name, pShain->age, pShain->gender);

    return 0;
}


// �Q�l�Fhttp://www9.plala.or.jp/sgwr-t/c/sec15-3.html
int structsample2()
{
    // �\���̂̃|�C���^�̐錾
    HUMAN* pShain;

    // �������m��
    pShain = (HUMAN*)malloc(sizeof(HUMAN) * 20);
    if (pShain == NULL)
    {
        return -1;
    }

    // �l��ݒ�
    pShain->id = 0;
    strcpy(pShain->name, "�R�c");
    pShain->age = 20;
    pShain->gender = GENDER_MAN;

    // �|�C���^��l��ς����ɎQ�ƃA�h���X�����炵���̃|�C���^�̃f�[�^��ݒ�
    // ���l��ς��Ă��܂���free����Ώۂ��킩��Ȃ��Ȃ��Ă��܂����߁B

    // �����̕��@�Ƃ��āA�ȉ��̂悤�ɐ擪�A�h���X��ێ����Ă������@������B
    //   HUMAN* firstShain = pShain;
    //   pShain++;
    //   ...(����)...
    //   pShain = firstShain;

    (pShain + 1)->id = 1;
    strcpy((pShain + 1)->name, "����");
    (pShain + 1)->age = 25;
    (pShain + 1)->gender = GENDER_WOMAN;

    // �o��
    printf("�o�͇@[%d][%s][%d][%d]\n", pShain[0].id, pShain[0].name, pShain[0].age, pShain[0].gender);
    printf("�o�͇A[%d][%s][%d][%d]\n", pShain[1].id, pShain[1].name, pShain[1].age, pShain[1].gender);
    printf("�o�͇B[%d][%s][%d][%d]\n", pShain->id, pShain->name, pShain->age, pShain->gender);
    printf("�o�͇C[%d][%s][%d][%d]\n", (pShain + 1)->id, (pShain + 1)->name, (pShain + 1)->age, (pShain + 1)->gender);

    // ���
    free(pShain);

    return 0;
}
