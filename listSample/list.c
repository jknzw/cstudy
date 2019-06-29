#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

int add(LIST_PERSON** list, PERSON person)
{
    LIST_PERSON* newlist = (LIST_PERSON*)malloc(sizeof(LIST_PERSON));
    if (newlist == NULL)
    {
        return -1;
    }
    newlist->person = person;
    newlist->next = NULL;

    while (*list != NULL) {
        list = &((*list)->next);
    }
    *list = newlist;

    return 0;
}

int release(LIST_PERSON** list)
{
    LIST_PERSON* next;
    LIST_PERSON* del;

    next = (*list)->next;

    // �S�|�C���^�̗̈�����
    while (next != NULL) {
        // ���̃A�h���X������ꍇ
        // ���̃A�h���X���폜�ΏۂƂ��Ď擾
        del = next;
        // ���̎��̃A�h���X��ێ�
        next = next->next;
        // ���̃A�h���X�̃��������������
        free(del);
    }
    // �ŏ��̃��������������
    free(*list);
}
